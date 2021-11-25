# 11.25(수) Part1 단위 테스트로 디버깅 및 코딩 표준 고치기
* memo    
  * ft_memmove    
동적할당 없이 overlap 구현   
void 일때는 간접 참조로 대입을 못 한다
  
  * ft_memcmp
    * 바이트 값을 비교할 때 unsigned char를 사용해야 한다    
1바이트에 있는 값에서 서로 큰지 비교하는데 unsigned를 사용하지 않으면 음수가 되서    
return 값인 매개변수끼리 뺄셈이 잘못되어 버린다
    * while 조건식과 ++ 연산 케이스 총 정리
       1. while 조건식에 ++연산을 하는 경우
       2. while 문 {} 안에서 ++연산을 하는 경우
<pre>
<code>
// 이 경우 i, p1, p2는 i < n조건에 걸려서 나갈 때 
// while문 안에서 ++을 했기 때문에 이미 ++된 상태로 됐다는 걸 명심하자
// 즉! 비교할 때 이미 값이 1칸 더 올라가있다
// 배열을 비교할 때 offset으로 0부터 시작하기 때문에 이때 배열 기준으로 +1 된 상태이다(while문에서 for문보다 위험한 경우)
// i는 n이 되었고 p1, p2는 비교할 대상에서 1칸 앞으로 간 상태이다
// p1[n - 1], p2[n - 1]을 비교해야하는데 [n]일 때 비교하고 있다
 i = 0;
	while (i < n && *p1 == *p2)
	{
		i++;
		p1++;
		p2++;
	}
	return (p1 - p2);
 
//따라서 이 코드도 틀리다
	i = 0;
	while (i < n && p1[i] == p2[i])
	{
		i++;
	}
	return (p1[i] - p2[i]);
}
</code>
</pre>
       4. 안 좋은 예 - 인덱스 접근과 포인터 연산 혼합하다가 쓰는 실수
<pre>
<code>
 i = 0;
	while (i < n && *p1 == *p2)
	{
		i++;
		p1++;
		p2++;
	}
	return (p1 - p2);
</code>
</pre>
       5. 안 좋은 예 - 조건식에 ++ 연산해서 하는 실수
<pre>
<code>
$(OBJS) : $(SRCS)
$(CC) $(CFLAGS) -c $< -o $@ -MD
</code>
</pre>    
       6. 좋은 에 - 인덱스와 포인터 연산 같이 쓰기
<pre>
<code>
$(OBJS) : $(SRCS)
$(CC) $(CFLAGS) -c $< -o $@ -MD
</code>
</pre>

* time      
23개 C라이브러리 함수 디버깅

# 11.25(수) How to make Makefile
* memo
makefile 작성.  
메이크파일에서 변수를 선언해서 전제 조건에 변수를 사용할 때 1개씩 가져오는 것이 아니라 여러 개 한꺼번에 가져온다   
반면에 변수를 선언해서 타겟에 넣으면 변수에 있는 값들을 1개씩 넣어준다
<pre>
<code>
$(OBJS) : $(SRCS)
$(CC) $(CFLAGS) -c $< -o $@ -MD
</code>
</pre>

* src  
메이크 파일에 대한 기본적인 설명 https://bowbowbow.tistory.com/12   
메이크 파일을 어떻게 사용할까? https://modoocode.com/311

* time 3.00
