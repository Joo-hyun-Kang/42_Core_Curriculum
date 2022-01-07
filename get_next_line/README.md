# 느낀점
## gnl에서는 운영체제 파일 시스템을 배움
## 자료구조에 대한 고민을 심하게 함 막상 구현은 어렵지 않았음
## 연결리스트를 쓰는 보너스 문제에서 왜 객체 지향이 생겼는지 감을 얻을 수 있었음

#  get_next_line는 어떤 프로젝트인가?
## get_next_line 요구사항
* 파일에서 '\n'까지 읽거나 한 줄이 없는 경우 그 파일의 EOF 전까지 읽는 함수
* 사용자가 BUFFER_SIZE를 지정해서 어느 정도 블록으로 읽어올 지 컴파일 시 define하여 전달
	* gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <파일들>.c
	* BUFFER_SIZE가 1이라도 BUFFER_SIZE가 10,000,000이라도 제대로 작동해야 함
* bonus파트로 다음과 같은 요구사항을 추가해서 제작할 수 있음
	* static 변수는 1개만 사용할 것
	* 파일의 리딩 스레드를 읽지 않은 채로 여러 파일들에서 자료를 읽어올 수 있을 것 
<br>

## 제약 사항
* 함수는 최대 10개를 넘을 수 없음
* 모든 함수는 최대 25줄을 넘을 수 없음
* lseek는 허용되지 않고 파일 읽기는 오로지 1번만 이루어져야 함
<br>

# 어떻게 구현하였는가?
## 기본적인 설계
![Frame 1gnl_structure_diagram](https://user-images.githubusercontent.com/68218329/148499831-730ed984-4513-44a9-a34f-38020ce64e5d.png)

## gnl 진행할 때 가장 신경쓴 부분은 자료구조
### gnl이 구조가 복잡해진 이유: BUFFER_SIZE를 외부에서 전달하여 블록 단위로 읽어야 함 + '\n'이 언제 나올 지 정해지지 않음
* BUFFER_SIZE를 외부에서 전달하여 블록 단위로 읽어야 함 : '\n'이 나온 후에 자료를 보존해야 함
* '\n'이 언제 나올 지 정해지지 않음 : BUFFER의 크기가 유동적으로 변해야 함

### Queue와 Table로 버퍼를 나눈 이유
* 처음에 진행할 때는 Queue와 Table을 따로 분리하지 않고 구현했다 그러나 이렇게 구현하는 경우 요구되는 2가지 기능이 상충된다는 걸 깨달았다
	* Queue의 기능인 계속해서 읽어오고 읽어온 부분이 EOF에 아닌 한 계속 보존해야 함
	* Table의 기능인 '\n'이 발견될 때까지 계속 Table의 크기를 늘려야 함
* 두 가지 기능을 같이 유지 시킬 경우 보존 + 늘리기라는 기능이 결합되어서 가득 찰 때마다 버퍼를 늘리고 기존의 자료들을 O(n)으로 복사해야했다
* 또한. '\n'이 불규칙적으로 들어올 수 있기 때문에 '\n'이 처음에만 늦게 들어온다면 버퍼의 크기가 쓸 데 없이 메모리를 많이 먹고 있는 위험이 있다
* 따라서, 레이어를 나누어서 읽고 보존하는 기능은 Queue로 '\n'을 발견하고 버퍼를 늘리는 기능은 Table로 분리했다
	* 이렇게 레이어를 나누어서 얻어지는 장점 : 서로 독립적인 기능을 원자적으로 수행하면서 성능 개선, 확장에 유리함

### Table 자료구조로 연결리스트를 선택한 이유
* Table은 정해둔 크기까지 '\n'이 발견되지 않으면 그 크기를 키워서 queue에서 자료를 받아올 수 있어야 한다
* 요구사항 상 '\n'이 어디까지 나온다는 언급이 없음으로 유연하게 크기를 키울 수 있어야 했다
* 동적할당 배열은 옵션에 들어있었으나 크기를 키울 때마다 기존 자료를 보존하기 위해서 memcpy()로 O(n)만큼 시간이 낭비된다는 점에 기각되었다
* 연결리스트는 자료를 복사하는 시간이 낭비되지 않지만 res에 복사할 때 탐색 시간, 늘어난 연결리스트를 free하는 시간이 들지만 그럼에도 동적할당보다 더 효율적이라고 생각했다.
<br>



# 왜? 
## read 함수 리턴 값
RETURN VALUES
     If successful, the number of bytes actually read is returned.  Upon reading end-of-file, zero is
     returned.  Otherwise, a -1 is returned and the global variable errno is set to indicate the error.

# 부가적인 지식
## 리눅스 출력 시 $는 줄바꿈 혹은 EOF, \n은 그냥 적는 건 특수문자가 아니라 텍스트일뿐
## 파일 시스템 콜
* 경로명을 따라가는 잃은 항상 파일 시스템의 루트에서 시작하며, 루트 디렉터리(root
directory)는 /로 표기된다. 파일 시스템이 디스크에서 가장 먼저 읽을 잃은 루트 디렉터리의 아이노드이다. 
루트 디౪터리의 아이노드는 어디에 있는가? 아이노드를 찾기위해서는 i-number를 알아야 한다.
일반적으로 어떤 파일이나 디౪터리의 i-number는
부모 디౪터리에서 찾을 수 있다. 루트는 부모가 ᨧ다 (정의상 ᨧ음). 루트 i-number는
“잘 알려진” 잃이어야 한다. 파일 시스템이 마운트될 때 이 값이 결정된다. 대부분의
Unix 파일 시스템에서는 루트 디౪터리의 아이노드 번호는 2번이다. 파일 시스템은
아이노드 번호 2번을 포함하는 블럭을 읽는다 (첫 번째 아이노드 블럭).
파일 시스템은 읽어들인 아이노드에서 데이터 블럭의 포인터를 추출한다. 포인터가
가리키는 블럭에는 루트 디౪터리의 내용이 들어 있다. 파일 시스템은 이 포인터들을
사용하여 디౪터리 정보를 읽고, foo라는 항목을 찾는다. 디౪터리에 많은 파일이
들어있을 수 있다. 예를 들어 3,000개. 이 경우, 모든 항목을 하나의 블럭에 저장할 수
ᨧ다. 하나의 디౪터리를 표현하기 위해 다수의 블럭이 사용된다. 하나 또는 그 이상의
디౪터리 데이터 블럭을 읽어서 foo에 대한 항목을 찾을 수 있다. foo 파일의 디౪터리
항목을 찾아서, foo의 아이노드 번호 (44라고 하자)를 파악한다. 우리는 이 아이노드
(44번 아이노드)가 필요하다.
다음 순서는 경로명을 따라가서 원하는 아이노드를 찾는다. 이 예제에서 파일 시스
템은 foo의 아이노드가 있는 블럭과 그에 대한 디౪터리 데이터를 읽은 후에 마침내
bar에 대한 아이노드 번호를 찾아낸다. 마지막 단계의 open()은 bar에 대한 아이노
드를 메모리로 읽어 들인다. 파일 시스템은 최종적으로 해당 파일에 대한 접근 권한을
확인하고, 이 프로세스의 open ile-table에서 파일 디스크립터를 할당받아 사용자에게
리턴한다.   
* 출처 : 운영체제 : 아주 쉬운 세 가지 이야기 [ch 40]   
## 파일 디스크립터와  open-file table
*지금까지는 위에서 다 설명했던 내용이다. 그 다음 과정에는 open-file table이라는 새로운 개념이 들어간다. open-file table은 open()함수에 의해 open된 파일의 list 형태로 나타낸 테이블이다. 즉 이 테이블에는 open된 파일이 모두 들어와 있다고 보면 된다.  
*open-file table은 결국 파일의 metadata가 저장되어 있는 주소값을 가지고 있는 것이고 그 각각의 index에 대한 주소가 바로 open()함수의 return 값이 되는 것이다. 이제 파일을 어떻게 access하는지 대략적으로 감을 잡았으리라고 본다. 그러면 이제는 조금 더 구체적으로 과정을 이야기 해보자. 방금전에 open-file table에 대해서 이야기를 했다.    
*그런데 이 open-file table은 사실 두 가지 형태로 존재한다. per-process open-file table 그리고 system-wide open-file table이다. per-process open-file table은 프로세스마다 가지고 있는 open-file table이다. system-wide open-file table은 시스템의 모든 open된 파일들에 대한 open-file table이다.    
* 출처: https://operatingsystems.tistory.com/entry/OS-File-System [Maybe]   
## window VS code 환경에서 파일 여러개 빌드하고 디버깅 하는 방법 
* wsl 설치, 우분투 설치
* gcc 설치 등을 위해서 업그레이드 https://blog.naver.com/PostView.nhn?isHttpsRedirect=true&blogId=lidaxi043682&logNo=221717515827
* vs 코드 리눅스로 실행 후 launch 에서 분할 컴파일이 되게 *.c로 수정 https://www.youtube.com/watch?v=DVyYnOHP4nY&t=441s&ab_channel=MichaelHoefer
* lanch, task 생성 gcc, /bin에 있는 gcc-9로 설정
* 마지막으로 https://sjkim-dev.tistory.com/26 c_cpp_프로퍼티 만들어주기
* 디버그는 잘 되는데 C라이브러리 안에 탐색하는 디버그는 안 되고(소스코드 못 보고) 그냥 내 코드 f10으로 보는 건 된다.
