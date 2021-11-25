# 11.25(수) Part1 단위 테스트로 디버깅 및 코딩 표준 고치기
* memo    
+ ft_memmove    
동적할당 없이 overlap 구현   
void 일때는 간접 참조로 대입을 못 한다  

+ ft_memcmp   
1바이트에 있는 값에서 서로 큰지 비교하는데 unsigned를 사용하지 않으면 음수가 되서    
return 값인 매개변수끼리 뺄셈이 잘못되어 버린다

* time      
23개 C라이브러리 함수 디버깅

# 11.25(수) How to make Makefile
* memo
makefile 작성.  
메이크파일에서 변수를 선언해서 전제 조건에 변수를 사용할 때 1개씩 가져오는 것이 아니라 여러 개 한꺼번에 가져온다   
반면에 변수를 선언해서 타겟에 넣으면 변수에 있는 값들을 1개씩 넣어준다
<pre>
<code>
$(OBJS) : $(OBJS)
$(CC) $(CFLAGS) -c $< -o $@ -MD
</code>
</pre>

* src  
메이크 파일에 대한 기본적인 설명 https://bowbowbow.tistory.com/12   
메이크 파일을 어떻게 사용할까? https://modoocode.com/311

* time 3.00
