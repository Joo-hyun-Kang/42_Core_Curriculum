#  get_next_line는 어떤 프로젝트인가?
### 1. 요구사항
* 파일에서 '\n'까지 읽거나 한 줄이 없는 경우 그 파일의 EOF 전까지 읽는 함수
* 사용자가 BUFFER_SIZE를 지정해서 어느 정도 블록으로 읽어올 지 컴파일 시 define하여 전달
	* gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <파일들>.c
	* BUFFER_SIZE가 1이라도 BUFFER_SIZE가 10,000,000이라도 제대로 작동해야 함
* 전체 파일을 읽어들인 다음에 한줄씩 처리하려 하는 것은 금지되어 있다.
* bonus파트로 다음과 같은 요구사항을 추가해서 제작할 수 있음
	* static 변수는 1개만 사용할 것
	* 파일의 리딩 스레드를 읽지 않은 채로 여러 파일들에서 자료를 읽어올 수 있을 것 
<br>

### 2. 제약 사항
* 함수는 최대 10개를 넘을 수 없음
* 모든 함수는 최대 25줄을 넘을 수 없음
* lseek는 허용되지 않고 파일 읽기는 오로지 1번만 이루어져야 함
<br>

# 어떻게 구현하였는가?
## 1. 기본적인 설계
![Frame 1gnl_structure_diagram](https://user-images.githubusercontent.com/68218329/148499831-730ed984-4513-44a9-a34f-38020ce64e5d.png)

<br>

## 2. 가장 고민한 부분은 자료구조이다
### BUFFER_SIZE를 외부에서 전달하여 블록 단위로 읽어야 함 + '\n'이 나올 거나 OR EOF 전까지 반환
* 위 2가지 조건이 get_next_line을 복잡하게 하는 요구사항임.
* BUFFER_SIZE를 외부에서 전달하여 블록 단위로 읽어야 함 : '\n'이 나온 후에 자료를 보존해야 함.
* '\n'이 언제 나올 지 정해지지 않음 : BUFFER의 크기가 유동적으로 변하여 '\n' 나올 때까지 EOF일 때까지 저장하고 반환해야 함.

<br>

### Queue와 Table로 버퍼를 나눈 이유
* 처음에 진행할 때는 Queue와 Table을 따로 분리하지 않고 구현했다. 그러나 이렇게 구현하는 경우 요구되는 2가지 기능이 상충된다는 걸 깨달았다.
	* Queue의 기능인 계속해서 읽어오고 읽어온 부분이 EOF에 아닌 한 계속 보존해야 함.
	* Table의 기능인 '\n'이 발견될 때까지 계속 Table의 크기를 늘려야 함.
* 두 가지 기능을 같이 유지 시킬 경우 보존 + 늘리기라는 기능이 결합되어서 가득 찰 때마다 버퍼를 늘리고 기존의 자료들을 O(n)으로 복사해야했다.
* 또한, '\n'이 불규칙적으로 들어올 수 있기 때문에 '\n'이 처음에만 늦게 들어온다면 버퍼의 크기가 쓸 데 없이 메모리를 많이 먹고 있는 위험이 있다.
* 따라서, 레이어를 나누어서 읽고 보존하는 기능은 Queue로 '\n'을 발견하고 버퍼를 늘리는 기능은 Table로 분리했다.
	* 이렇게 레이어를 나누어서 얻어지는 장점 : 서로 독립적인 기능을 원자적으로 수행하면서 성능 개선, 확장에 유리하다.

<br>

### Table 자료구조로 연결리스트를 선택한 이유
* Table은 정해둔 크기까지 '\n'이 발견되지 않으면 그 크기를 키워서 queue에서 자료를 받아올 수 있어야 한다
* 요구사항 상 '\n'이 어디까지 나온다는 언급이 없음으로 유연하게 크기를 키울 수 있어야 했다
* 동적할당 배열은 옵션에 들어있었으나 크기를 키울 때마다 기존 자료를 보존하기 위해서 memcpy()로 O(n)만큼 시간이 낭비된다는 점에 기각되었다
* 연결리스트는 자료를 복사하는 시간이 낭비되지 않지만 res에 복사할 때 탐색 시간, 늘어난 연결리스트를 free하는 시간이 들지만 그럼에도 동적할당보다 더 효율적이라고 생각했다.

<br>

## 3. read()가 실패할 때 에러처리와 EOF 처리
### 에러를 방어하는 곳은 read()함수를 사용하는 try_enqueue_fd 처리한다
* 구현 시에 모든 부분에서 에러처리를 한다는 것은 코드의 가독성을 해치고 디버깅도 힘들기에, 에러는 내 구현범위를 넘어서는 경계인 try_enqueue_fd에서 막는다.
* 구현을 최초에 try_enqueue_fd에서 모든 에러를 발견하고 발견되면 null을 반환하게끔 구현하였고, 내부에서는 assert를 이용해서 에러를 잡게 구현하였다.
* int	try_enqueue_fd(t_queue *queue_pa, int fd)
	
	
		
		int	ret;

		ret = read(fd, queue_pa->buffer_pa, BUFFER_SIZE);
		if (ret < 0)
			return (FALSE);
		if (ret == 0)
		{
			queue_pa->is_EOF = TRUE;
			queue_pa->num_count = 0;
			return (FALSE);
		}
		if (ret < BUFFER_SIZE)
		{
			queue_pa->num_count = ret;
			queue_pa->last_count = ret;
			queue_pa->is_EOF = TRUE;
		}
		else
			queue_pa->num_count = BUFFER_SIZE;
		return (TRUE);
		
	


<br>

## 4. 보너스 파트 자료구조 : Linked list vs Hast set
### 보너스 파트에서 리딩 스레드를 유지하기 위한 자료구조는 Linked list를 선택했다
* 파일 디스크립터가 몇개까지 들어올 지는 시스템마다 다르다. 검색결과 설정에 따라 512, 1024, 2048 등 크기가 여러 개로 존재한다. 
* 실제 상용 API였다면 사용하다가 사용하는 시스템에 따라 몇 개의 파일 fd를 사용하는 지 알게 되면 그 때 해시 세트을 이용해서 리펙토링 하는 것이 옳다고 생각했다.
* 해시 세트를 이용하면 파일 디스크립터 탐색 속도가 Linked list에 비해서 매우 빠르다. 일반적으로 O(1)을 기대할 수 있다.

<br>
<br>

# 이번 프로젝트를 진행하면서 느낀점
#### 1. 구현은 어렵지 않지만 요구사항이 막연한 상태에서 보다 효율적이고 포괄적인 자료구조를 위해서 고민을 굉장히 많이 하였다.
#### 2. 버퍼를 큐와 테이블로 분리하면서 서로 결합된 로직을 분리하여 레이어로 얻는 성능 개선, 모듈화와 확장성, 코드 가독성 강화를 경험하였다.
#### 3. 25줄 제한과 함수 10개 제한으로 코드를 깔끔하고 가독성 높게 작성하기 위해서 올바른 에러처리 방법에 대해 고민하였다.
#### 4. gnl에서는 운영체제 파일 시스템과 시스템 콜에  배울 수 있었다.

<br>
<br>

# 프로젝트를 진행하면서 배운 지식들
### 한 파일을 여러 개 열었을 때 파일 디스크립트는 어떻게 되는가?
* 같은 파일을 한 프로세스에서 2번 열었을 때 process의 파일 테이블에 새로운 fd가 생성된다.
* 그리고 각 fd마다 system 파일 테이블에 독자적인 파일 상태 플러그, 파일 offset, inode주소를 가진다.
* 단, 가르키는 아이노드는 같음 말그대로 주소값은 그대로고 포인터 구조체 변수가 새로 생성된다고 할 수 있다.

<br>

### 파일 시스템 콜
* 경로명을 따라가는 잃은 항상 파일 시스템의 루트에서 시작하며, 루트 디렉터리(rootdirectory)는 /로 표기된다. 파일 시스템이 디스크에서 가장 먼저 읽을 잃은 루트 디렉터리의 아이노드이다. 
* 다음 순서는 경로명을 따라가서 원하는 아이노드를 찾는다. 이 예제에서 파일 시스템은 foo의 아이노드가 있는 블럭과 그에 대한 디렉터리 데이터를 읽은 후에 마침내 ar에 대한 아이노드 번호를 찾아낸다. 
* 마지막 단계의 open()은 bar에 대한 아이노드를 메모리로 읽어 들인다. 파일 시스템은 최종적으로 해당 파일에 대한 접근 권한을 인하고, 이 프로세스의 open ile-table에서 파일 디스크립터를 할당받아 사용자에게 리턴한다.   
* 출처 : 운영체제 : 아주 쉬운 세 가지 이야기 [ch 40]   

<br>

### 파일 디스크립터와  open-file table
* 지금까지는 위에서 다 설명했던 내용이다. 그 다음 과정에는 open-file table이라는 새로운 개념이 들어간다. open-file table은 open()함수에 의해 open된 파일의 list 형태로 나타낸 테이블이다. 즉 이 테이블에는 open된 파일이 모두 들어와 있다고 보면 된다.  
* open-file table은 결국 파일의 metadata가 저장되어 있는 주소값을 가지고 있는 것이고 그 각각의 index에 대한 주소가 바로 open()함수의 return 값이 되는 것이다. 이제 파일을 어떻게 access하는지 대략적으로 감을 잡았으리라고 본다. 그러면 이제는 조금 더 구체적으로 과정을 이야기 해보자. 방금전에 open-file table에 대해서 이야기를 했다.    
* 그런데 이 open-file table은 사실 두 가지 형태로 존재한다. per-process open-file table 그리고 system-wide open-file table이다. per-process open-file table은 프로세스마다 가지고 있는 open-file table이다. system-wide open-file table은 시스템의 모든 open된 파일들에 대한 open-file table이다.    
* 출처: https://operatingsystems.tistory.com/entry/OS-File-System [Maybe]

<br>

### window VS code 환경에서 파일 여러개 빌드하고 디버깅 하는 방법 
* wsl 설치, 우분투 설치한다.
	* https://www.lainyzine.com/ko/article/how-to-install-wsl2-and-use-linux-on-windows-10/
* gcc 설치 등을 위해서 우분투를 업그레이드한다. 
	* https://blog.naver.com/PostView.nhn?isHttpsRedirect=true&blogId=lidaxi043682&logNo=221717515827
* https://www.youtube.com/watch?v=DVyYnOHP4nY&t=441s&ab_channel=MichaelHoefer
	* VScode를 WSL로 실행 후
	* C/C++ 추가기능 설치(동영상에는 나와있지 않음 모른다면 따로 검색하서 알아볼 것)
	* launch 에서 분할 컴파일이 되게 *.c로 수정한다.
	* lanch, task 생성 gcc, /bin에 있는 gcc-9로 설정해서 디버깅을 시도한다.
