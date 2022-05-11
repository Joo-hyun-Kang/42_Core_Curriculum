#include <stdio.h>
#include <assert.h>
#include "libft.h"

# define true (1);
# define false (0);

# define ARRAYLIST_BASIC_CAPACITY (10)

typedef struct arraylist {
	int* pa_arr;
	int length;
	int capacity;
} arraylist_t

int is_arraylist_full(arraylist_t *arraylist) {
	if (arraylist->length >= arraylist->capacity) 
	{
		return (true);
	}
	return (false)
}

int allocate_arraylist(arraylist_t *arraylist) {
	if (arraylist->pa_arr == NULL || arraylist->capacity == 0)
	{
		arraylist->pa_arr = (int *)malloc(ARRAYLIST_BASIC_CAPACITY * sizeof(int));
		arraylist->length = 0;
		arraylist->capacity = 0;
	}
	else
	{
		int *tmp = (int *)malloc(arraylist->capacity * 2 * sizeof(int));
		assert(capacity >= length);
		ft_memcpy(tmp, arraylist->pa_arr, length);
		free(pa_arr);
		pa_arr = tmp;
		tmp = NULL:
		arraylist->capacity *= 2;
	}
}

int

int is_parse_argv_malloc(int argc, char **argv, arraylist_t *arraylist);

int main(int argc, char** argv)
{
    arraylist_t pa_arraylist;
    
    is_parse_argv_malloc(argc, argv, pa_arraylist);
    
    
}

// 여기서 입력값 전부 방어한다

// 함수의 후조건
// 1. 입력이 잘못 들어오는 경우 -1 return
// 2. 입력이 잘 들어오는 경우 parse해서 개수 전달한다 
int is_parse_argv_malloc(int argc, char **argv, arraylist_t *pa_arraylist);
{
	// 들어오는게 "12" "3" 4 5 라고 해보자
    
	// 인자가 없을 때
	if (argc < 2)
    {
       return (-1);
    }
	// 어차피 argv는 문자열로 저장되어 있다? ㅇㅇ
	// 문자열인 argv를 가져와서 처리하면 되는데
	// ""가 들어가나? --> 실험 ㄱㄱ
	// 

    // "1" "2" 34 
    // 1 2 3 4
    // "Error"
    // 정수가 아닌 값에 대한
    // 정수가 중복해서 들어왔을 떄 
    // Int보다 큰 값, 작은 값일 떄

    // 아무것도 출력이 안 될 때
    // 인자 없을 때, 정렬 된 거, 인자 1개 일 때
	char **temp = argv;
	int i = 1;
	while (i < 2)
	{
		char **pa_splited_str = ft_split(temp[i], ' ');		
			
			// split의 후조건
			// 띄어쓰기로 나눈 문자
			// 이 문자는 숫자일수도 숫자가 아닐 수도 있음
			// split에서 몇개를 주는 지 까봐야 함 길이를 구해서 그만큼 atoi를 구해야함

			// atoi의 선조건 --> 숫자가 아닐 경우 어떻게 처리?
		pa_arraylist->pa_arr = ft_atoi()
		i++;
		// "1 2 3" 4 5
		// 1 2 3\04\05\0
	}
	// 0 1 2 argc는 3
	// index는 2번 도는데 
	// 1 1
	// 2 2
	// 3

	//정수가 아닌 값에 대해서
	//Int보다 큰 값, 작은 값 일 때
	//정수가 중복
	//아무것도 출력이 안 될 때
	//인자가 
	return 0;
}