#include "push_swap.h"

static char	**ft_do_split_malloc_or_null(const char *s, char c, char **out_res);
static int	get_w_length(const char *str, char c);
static int	is_charset(char str, char c);
static void	do_free_malloc(char **res, char **tmp_res);
char	**ft_split(const char *s, char c);

static int	ft_isspace(char ch);
int	ft_atoi(const char *str, int *out_res);
int	ft_isdigit(int c);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memcpy(void *dst, const void *src, size_t n);

void print_error_exit();

int add_arraylist(arraylist_t *arraylist, int value);
int is_arraylist_full(arraylist_t *arraylist);
int allocate_arraylist(arraylist_t *arraylist);
void free_arraylist(arraylist_t *arraylist);
void is_parse_argv_malloc(int argc, char **argv, arraylist_t *arraylist);

void get_optiml_pivot(arraylist_t *arraylist, stack_t *stack);
void quick_sort(int start, int end, arraylist_t *arraylist, int *is_eailer_sorted);
int divdie_and_conquer(int left, int right, int *nums);
void swap(int *nums, int a, int b);
int	is_overlap(arraylist_t *arraylist);

///////라이브러리 가져와서 쓰는 함수////////

char	**ft_split(const char *s, char c) 
{
	char		**result;
	const char	*tmp_s;
	int			is_word;
	int			count;

	is_word = 0;
	count = 0;
	tmp_s = s;
	while (*tmp_s != '\0')
	{
		if (is_charset(*tmp_s, c) && is_word == 1)
		{
			is_word = 0;
		}
		else if (!is_charset(*tmp_s, c) && is_word == 0)
		{
			is_word = 1;
			count++;
		}
		tmp_s++;
	}
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (result == NULL)
		return (NULL);
	return (ft_do_split_malloc_or_null(s, c, result));
}

static char	**ft_do_split_malloc_or_null(const char *s, char c, char **out_res)
{
	char	**t_result;
	int		is_word;

	t_result = out_res;
	is_word = 0;
	while (*s != '\0')
	{
		if (is_charset(*s, c) && is_word == 1)
			is_word = 0;
		else if (!is_charset(*s, c) && is_word == 0)
		{
			is_word = 1;
			*t_result = (char *)malloc(1 * (get_w_length(s, c) + 1));
			if (*t_result == NULL)
			{
				do_free_malloc(out_res, t_result);
				return (NULL);
			}
			ft_strlcpy(*t_result, s, get_w_length(s, c) + 1);
			t_result++;
		}
		s++;
	}
	*t_result = NULL;
	return (out_res);
}

static int	get_w_length(const char *str, char c)
{
	const char	*p;
	int			length;

	p = str;
	length = 0;
	while (*p != '\0' && is_charset(*p, c) == 0)
	{
		length++;
		p++;
	}
	return (length);
}

static int	is_charset(char str, char c)
{
	if (str == c)
	{
		return (1);
	}
	return (0);
}

static void	do_free_malloc(char **res, char **tmp_res)
{
	char	**p;
	size_t	count;
	size_t	i;

	count = tmp_res - res;
	i = 0;
	p = res;
	while (i < count)
	{
		free(*p);
		i++;
		p++;
	}
	free(res);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p++ != '\0')
	{
	}
	return (p - s - 1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && *src != '\0')
	{
		*dst++ = *src++;
		i++;
	}	
	if (dstsize != 0)
		*dst = '\0';
	while (*src != '\0')
	{
		src++;
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_temp;
	char	*src_temp;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_temp = (char *)dst;
	src_temp = (char *)src;
	i = 0;
	while (i < n)
	{
		*dst_temp++ = *src_temp++;
		i++;
	}
	return (dst);
}


//////////라이브러리 수정해서 쓰는 함수////////////////////////////

/*
* 후조건
* - int 범위 문자열은 숫자로 반환
* - int 범위 넘어서는 숫자는 -1 반환
* - 숫자가 아닌 경우 0 반환
*/

static int	ft_isspace(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v'
		|| ch == '\f' || ch == '\r' || ch == ' ')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str, int *out_res)
{
	int					sign;
	int					is_digit;
	unsigned long long	result;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	is_digit = false;
	while (ft_isdigit(*str))
	{
		is_digit = true;
		result *= 10;
		result += *str - '0';
		//Int 표현 범위 –2,147,483,648 ~ 2,147,483,647
		if (result > 2147483647 && sign == 1)
			return (false);
		if (result > 2147483648 && sign == -1)
			return (false);
		str++;
	}
	if (!is_digit) 
		return (false);
	*out_res = (int)(sign * result);
	return (true);
}


////////////push swap////////////////////////

int add_arraylist(arraylist_t *arraylist, int value) {
	if (!is_arraylist_full(arraylist)) {
		arraylist->pa_arr[arraylist->length] = value;
		arraylist->length++;
		return (true);
	}
	if (is_arraylist_full(arraylist)) {
		allocate_arraylist(arraylist);
		return add_arraylist(arraylist, value);
	}
	return (false);
}

int is_arraylist_full(arraylist_t *arraylist) {
	if (arraylist->length >= arraylist->capacity) 
	{
		return (true);
	}
	return (false);
}

int allocate_arraylist(arraylist_t *arraylist) {
	if (arraylist->pa_arr == NULL || arraylist->capacity == 0)
	{
		arraylist->pa_arr = (int *)malloc(ARRAYLIST_BASIC_CAPACITY * sizeof(int));
		arraylist->length = 0;
		arraylist->capacity = ARRAYLIST_BASIC_CAPACITY;
		return (true);
	}
	
	if (arraylist->pa_arr != NULL && arraylist->capacity != 0)
	{
		int *tmp = (int *)malloc(arraylist->capacity * 2 * sizeof(int));
		assert(arraylist->capacity >= arraylist->length);
		ft_memcpy(tmp, arraylist->pa_arr, arraylist->length);
		free(arraylist->pa_arr);
		arraylist->pa_arr = tmp;
		tmp = NULL;
		arraylist->capacity *= 2;
		return (true);
	}

	return (false);
}

void free_arraylist(arraylist_t *arraylist) {
	assert(arraylist->pa_arr != NULL);
	free(arraylist->pa_arr);
	arraylist->pa_arr = NULL;
	assert(arraylist->capacity != 0);
	arraylist->capacity = 0;
	assert(arraylist->length != 0);
	arraylist->length = 0;
}

int main(int argc, char** argv)
{
    arraylist_t pa_arraylist;
	ft_stack_t pa_stack_a;
	ft_stack_t pa_stack_b;
	ft_stack_t pa_pivot;

    assert(allocate_arraylist(&pa_arraylist) == true);
    is_parse_argv_malloc(argc, argv, &pa_arraylist);
	get_optiml_pivot(&pa_arraylist, &pa_pivot);

	for (int i = 0; i < pa_arraylist.length; i++) {
		printf("%d\n", pa_arraylist.pa_arr[i]);
	}

	// 최적 피봇 구하기
	// 팝 인큐 디큐 구현
	// sa, sb 등 구현
	// sort하기
	


	free_arraylist(&pa_arraylist);
	//free_stack
	//free_pivot
}
//내 로직에서 체크할 것
//-빈칸이 있는 경우
//"    1" 4 2

// pivot을 따로 stack에서 빼고 pivot을 구하셈
// 어째든 둘 다 링크스 리스트에서 스택에서 추가하고 빼는 걸 구현해야 함
// 넣어야 할 것은 스택에 새로운 노드를 추가하는 것
// pivot에 새로운 노드를 추가하는 것
// 나중에 sort 할 때 옮기는 것 -> 추가하고 빼는 걸 이용한다

// 함수의 선조건
// 1. 할당된 arraylist에 parsing된 데이터가 있어야 함
// 2. 할당되지 않은 pivot을 받음 NULL어야 함
// 함수의 후조건
// 1. 입력 데이터가 중복된 숫자가 들어왔을 떄 Error 출력하고 종료
// 2. 입력 데이터가 정렬된 거 일 때 아무것도 출력하지 않고 그냥 종료
// 3. stack->pivot의 최적의 피봇을 linked list로 반환
void get_optiml_pivot(arraylist_t *arraylist, ft_stack_t *pivot) 
{
	int *p = arraylist->pa_arr;
	int len = arraylist->length;
	int is_eailer_sorted = false;
	quick_sort(0, len - 1, arraylist, &is_eailer_sorted);
	// 예외처리 4: 중복된 숫자가 들어왔을 때 Error 출력하고 종료
	if (is_overlap(arraylist))
		print_error_exit();
	// 예외처리 5: 정렬된 거 일 때 아무것도 출력하지 않고 그냥 종료
	if (is_eailer_sorted)
		exit(0);
	// 최적의 피봇 구하기
	// 	

}

int	is_overlap(arraylist_t *arraylist)
{
	int	i;

	i = 1;
	while (i < arraylist->length)
	{
		if (arraylist->pa_arr[i - 1] == arraylist->pa_arr[i])
		{
			return (true);
		}
		i++;
	}
	return (false);
}

void quick_sort(int start, int end, arraylist_t *arraylist, int *is_eailer_sorted) 
{
	if (start >= end)
	{
		return;
	}

	int pivot = end;
	int pivot_pos = divdie_and_conquer(start, pivot, arraylist->pa_arr);

	//최초 정렬 시 pivot과 poivot_pos가 같으면 이미 정렬되어 있음
	if (start == 0 && end == arraylist->length - 1 && pivot == pivot_pos)
		*is_eailer_sorted = true;

	quick_sort(start, pivot_pos - 1, arraylist, is_eailer_sorted);
	quick_sort(pivot_pos + 1, end, arraylist, is_eailer_sorted);
}

int divdie_and_conquer(int left, int right, int *nums)
{
	int swap_pos = left;
	int pivot = nums[right];
	int i = left;
	while (i < right)
	{
		if (nums[i] < pivot)
		{
			swap(nums, i, swap_pos);
			swap_pos++;
		}
		i++;
	}
	swap(nums, right, swap_pos);
	return (swap_pos);
}

void swap(int *nums, int a, int b)
{
	int	temp;

	temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}

// 함수의 후조건 : 입력 값 방어함수
// 1. 입력이 잘못 들어오는 경우 예외처리에서 프로그램 종료
// 2. 입력이 잘 들어오는 경우 parse해서 개수 전달한다 
void is_parse_argv_malloc(int argc, char **argv, arraylist_t *pa_arraylist)
{
	// 나중에 처리할 거 -> 배열이 정렬되서 들어오는 경우, 인자가 1개뿐일 경우
	// 처리한 건데 수정할 것 -> 숫자가 아닌 값이 들어왔을 때, int범위를 넘어설 때 --> Error표시하기

	// 예외처리 1: 인자가 없을 때 아무것도 출력하지 않고 그냥 종료
	if (argc < 2)
    {
       exit(0);
    }

	char **temp_argv = argv;
	int i = 1;
	while (i < argc)
	{
		char **pa_splited_str = ft_split(temp_argv[i], ' ');
		char **pp = pa_splited_str;
		int length_splited_str = 0;

		while (*pp != NULL)
		{	
			int value = 0;			
			// 예외처리 2: 숫자가 아닌 경우 Error 콘솔에 출력하고 종료
			// 예외처리 3: Int범위를 넘어서는 경우 Error 콘솔에 출력하고 종료
			if (ft_atoi(*pp, &value) == false)
				print_error_exit();
			add_arraylist(pa_arraylist, value);
			pp++;
		}
		i++;
		free(pa_splited_str);
		pa_splited_str = NULL;
	}

	// 예외처리 6: 인자가 1개 일 때 아무것도 출력하지 않고 그냥 종료
	// 예외처리 7: "", " "만 들어왔을 떄 아무것도 하지 않고 종료
	// ""는 '/0'이기 때문에 여기서 들어올 수 atoi를 안 돌고 나감
	// " "는 ' '로 split을 하기 때문에 널문자라서 atoi를 안 돌고 나감
	if (pa_arraylist->length == 0 || pa_arraylist->length == 1)
	{
		exit(0);
	}
}

void push_stack(ft_stack_t *stack, int content)
{
	linkedlist_t *new_lst;
	
	if (stack->top == NULL) 
	{
		stack->top = ft_lstnew_malloc(content);
		stack->bottom = stack->top;
		stack->size++;
	}
	new_lst = ft_lstnew_malloc(content);
	new_lst->next = stack->root;
	stack->top = new_lst;
	stack->size++;
}

int pop_stack(ft_stack_t *stack)
{
	int value;
	
	value = stack->top->value;
	//POCU lab2 Remove 코드 참고해

}

void print_error_exit()
{
	write(2, "Error\n", 6);
	exit(0);
}

//push_front 검증 필!
void push_front(linkedlist_t **root, int content)
{
	linkedlist_t	*new;

	new = ft_lstnew_malloc(content);
	ft_lstadd_front(root, new);
}

linkedlist_t	*ft_lstnew_malloc(int content)
{
	linkedlist_t	*head;

	head = (linkedlist_t *)malloc(sizeof(linkedlist_t));
	if (head == NULL)
		return (NULL);
	head->value = content;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

void	ft_lstadd_front(linkedlist_t **lst, linkedlist_t *new)
{
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		new->next = *lst;
		
		*lst = new;
	}
}

void push_back(linkedlist_t **end, int content)
{
	linkedlist_t	*new;

	new = ft_lstnew_malloc(content);
	ft_lstadd_front(end, new);
}

///////////