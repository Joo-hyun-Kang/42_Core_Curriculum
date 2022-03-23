
# ft_printf는 어떤 프로젝트인가?



# ft_printf를 어떻게 구현했는가?


### 이슈 : %뒤에 다른 글자가 오는 경우
* 경고를 던져주고, %만 출력함

### 이슈 : %뒤에 것들은 다 모든 정수형은 int로 승격되는데 이거 문자열은 어떻게 읽음?

### 이슈 : printf가 버퍼를 가지지 말아야 한다는 이유는 아래코드에서 p_pa 줄바꿈이 없는 경우 출력이 안 되서
stdin에 printf가 출력을 하는데 얘는 기본적으로 라인 버퍼링 그래서 줄바꿈이 없는 애는 fflush(stdout)을 해야함

	while (i < n)
	{
		p_pa = get_next_line(fd);
		printf("%s", p_pa);
		fflush(stdout);
		free(p_pa);
		i++;
	}


### 이슈 : You have to recode the libc’s printf function의 의미


### 이슈 : va_arg에서 type이 자동으로 승격되는지 여부
ㅇㅇ 승격됌     

   va_arg()

If there is no next argument, or if type is not compatible with the type of the actual next argument (as promoted according to the default argument promotions), random errors will occur.


https://stackoverflow.com/questions/28054194/char-type-in-va-arg#:~:text=So%20a%20variadic%20function%20can,all%20functions%20behaved%20this%20way





### logic
// f : 모든 문자열 format

{
// (E)ft_printf : 어떤 문자열에서 %cspdiuxX%를 발견하면 해당하는 가변인자를 찾아서 출력한다
// (1) (E)Cx & (E)Sx


}

{
	// (E)Cx : 어떤 문자열에서 '%c'를 발견하면 해당하는 가변인자를 찾아서 출력한다

	// A : %c가 여러개 들어오더라도 문제가 없다 
	// B : %c가 아닌 %%, %. %%c 등도 고려되어 있다
	// C : 가변인자가 character로 들어와도 va_arg인자로 int를 넣어도 문제가 없다 

	// (1) 1 & 2 & 4 -> A & B 
	//		1: format을 2번 상승했을 때 T
	//		2: format + 1이 다른 메모리 접근하지 않는다 T
	//		[4]: '%' 컴파일 에러가 난다 T
	// (2) 3 -> C
	//		3: 매개변수가 컴파일 시 최소 4바이트씩 끊어진다 T
}

{
	// (E)Sx : 어떤 문자열에서 '%s'를 발견하면 해당하는 가변인자를 찾아서 출력한다

	// A : %s가 여러개 들어오더라도 문제가 없다 
	// B : %s가 아닌 %%, %. %%c 등도 고려되어 있다
	// C : 가변인자가 string로 들어와도 va_arg인자로 char*를 넣어도 문제가 없다
	// D : libft 라이브러리를 사용하더라도 문제가 없다 

	// (0) (E)Cx
	// (1) 1 & 2 & 4 -> A & B 
	//		1: format을 2번 상승했을 때 
	//		2: format + 1이 다른 메모리 접근하지 않는다 
	//		[4]: '%'는 무시된다 
	// (2) 3 & 6-> C
	//		3: printf에서 승격시키는 건 기본데이터형에 국한된다
	//		6: gcc -o 플러그 위치를 제대로 해야 실행파일이 새롭게 만들어진다
	// (3) 4 & 5 -> D
	//		4: libft 라이브러리 a파일에 대해서 컴파일 명령어를 수정해준다
	//		5: libft 헤더 파일을 printf에 인클루드 해준다
}

{
	// (E)Px : 어떤 문자열에서 '%p'를 발견하면 해당하는 가변인자를 찾아서 출력한다

	// A : null이 들어오면 (nil)을 출력한다
	// B : 포인터 p의 메모리 주소를 출력한다
	

	// (0) (E)Cx & (E)Sx
	// (1) A
	// (2) 1 & 2 -> B
	//  0 : 리틀엔디언으로 출력한다
	//	1 : 메모리 주소 표현은 6바이트이다 T
			포인터의 주소는 8바이트이지만 실제 사용하는 건 6바이트만 https://stackoverflow.com/questions/11515662/if-a-pointers-address-is-64-bits-why-does-it-appear-as-6-bytes-when-printed
	//  2: 채점은 64바이트로 진행된다

}

