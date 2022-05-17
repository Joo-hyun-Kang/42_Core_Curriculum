#include "push_swap.h"

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
	ft_stack_t pa_out_queue;

    assert(allocate_arraylist(&pa_arraylist) == true);
    is_parse_argv_malloc(argc, argv, &pa_arraylist);
	get_optiml_pivot(&pa_arraylist, &pa_pivot);
	ft_set_stack(&pa_arraylist, &pa_stack_a, true);
	ft_set_stack(&pa_arraylist, &pa_stack_b, false);

	for (int i = 0; i < pa_arraylist.length; i++) {
		printf("%d\n", pa_arraylist.pa_arr[i]);
	}

	free_arraylist(&pa_arraylist);
	ft_sort(&pa_stack_a, &pa_stack_b, &pa_pivot, &pa_out_queue);



	printf("\n");

	linkedlist_t *temp = pa_pivot.front;
	while (temp != NULL)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}

	ft_free(&pa_stack_a);
	ft_free(&pa_stack_b);
	ft_free(&pa_pivot);
	temp = pa_out_queue.front;

	while (temp != NULL)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	
	
	ft_free(&pa_out_queue);
	//제출 전 어서트 날리기
}

// 함수의 선조건
// 1. 할당된 arraylist에 parsing된 데이터가 있어야 함
// 2. 할당되지 않은 pivot을 받음 NULL어야 함
// 함수의 후조건
// 1. 입력 데이터가 중복된 숫자가 들어왔을 떄 Error 출력하고 종료
// 2. 입력 데이터가 정렬된 거 일 때 아무것도 출력하지 않고 그냥 종료
// 3. stack->pivot의 최적의 피봇을 linked list로 반환
void	get_optiml_pivot(arraylist_t *arraylist, ft_stack_t *pivot) 
{
	int *arr_copy;
	int	i;
	int	len;

	len = arraylist->length;
	arr_copy = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		arr_copy[i] = arraylist->pa_arr[i];
		i++;
	}
	int is_eailer_sorted = false;
	quick_sort(0, len - 1, arr_copy, &is_eailer_sorted, len);
	// 예외처리 4: 중복된 숫자가 들어왔을 때 Error 출력하고 종료
	if (is_overlap(arr_copy, len))
		print_error_exit();
	// 예외처리 5: 정렬된 거 일 때 아무것도 출력하지 않고 그냥 종료
	if (is_eailer_sorted)
		exit(0);
	get_optimal_pivot_recursive(arr_copy, pivot, 0, len - 1);
	free(arr_copy);
	arr_copy = NULL;
}

void	get_optimal_pivot_recursive(int *arr, ft_stack_t *stack, int start, int end)
{
	int	mid;

	if (end - start <= 2)
		return ;

	mid = (start + end) / 2;
	ft_enqueue(stack, arr[mid]);
	
	get_optimal_pivot_recursive(arr, stack, mid + 1, end);
	get_optimal_pivot_recursive(arr, stack, start, mid);
}

int	is_overlap(int *arr, int length)
{
	int	i;

	i = 1;
	while (i < length)
	{
		if (arr[i - 1] == arr[i])
		{
			return (true);
		}
		i++;
	}
	return (false);
}

void quick_sort(int start, int end, int *arr, int *is_eailer_sorted, int length) 
{
	if (start >= end)
	{
		return;
	}

	int pivot = end;
	int pivot_pos = divdie_and_conquer(start, pivot, arr);

	//최초 정렬 시 pivot과 poivot_pos가 같으면 이미 정렬되어 있음
	if (start == 0 && end == length - 1 && pivot == pivot_pos)
		*is_eailer_sorted = true;

	quick_sort(start, pivot_pos - 1, arr, is_eailer_sorted, length);
	quick_sort(pivot_pos + 1, end, arr, is_eailer_sorted, length);
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

void print_error_exit()
{
	write(2, "Error\n", 6);
	exit(0);
}

void ft_push(ft_stack_t *stack, int content)
{
	linkedlist_t *new_lst;
	
	if (stack->size == 0) 
	{
		stack->front = ft_lstnew_malloc(content);
		stack->back = stack->front;
	}
	else
	{
		new_lst = ft_lstnew_malloc(content);
		new_lst->next = stack->front;
		stack->front = new_lst;
	}
	stack->size++;
}

void ft_enqueue(ft_stack_t *stack, int content)
{
	if (stack->size == 0)
	{
		stack->front = ft_lstnew_malloc(content);
		stack->back = stack->front;
	}
	else
	{
		stack->back->next = ft_lstnew_malloc(content);
		stack->back = stack->back->next;
	}
	stack->size++;
}

int	ft_pop_front(ft_stack_t *stack)
{
	int	result;

	assert(stack->size != 0);
	result = stack->front->value;
	stack->front = ft_remove(stack);
	stack->size--;

	if (stack->size == 0)
	{
		stack->back = NULL;
	}

	return (result);
}

int	ft_pop_back(ft_stack_t *stack)
{
	int				result;
	int				i;
	linkedlist_t	*prev_back;

	assert(stack->size != 0);
	if (stack->size == 1)
	{
		return (ft_pop_front(stack));
	}
	i = 1;
	prev_back = stack->front;
	while (i < stack->size - 1)
	{
		prev_back = prev_back->next;
		i++;
	}
	result = stack->back->value;
	free(stack->back);
	stack->back = prev_back;
	stack->size--;
	return (result);
}

int ft_peak(ft_stack_t *stack)
{
	int result;
	
	assert(stack->size != 0);
	result = stack->front->value;
	return (result);
}

linkedlist_t *ft_remove(ft_stack_t *rootOrNull)
{
	linkedlist_t	*result;
	
	if (rootOrNull->size == 0)
	{
		return (rootOrNull->front);
	}
	result = rootOrNull->front->next;
	rootOrNull->front->next = NULL;
	free(rootOrNull->front);
	rootOrNull->front = NULL;
	return (result);
}

linkedlist_t	*ft_lstnew_malloc(int content)
{
	linkedlist_t	*head;

	head = (linkedlist_t *)malloc(sizeof(linkedlist_t));
	if (head == NULL)
		return (NULL);
	head->value = content;
	head->next = NULL;
	return (head);
}

void ft_free(ft_stack_t *stack)
{
	linkedlist_t	*temp;

	while (stack->front != NULL)
	{
		temp = stack->front->next;
		free(stack->front);
		stack->front = temp;
		stack->size--;
	}
	//assert(stack->size == 0);
	stack->front = NULL;
	stack->back = NULL;
}

void ft_sa(ft_stack_t *a, ft_stack_t *queue)
{
	int	top;
	int	second_top;

	top = ft_pop_front(a);
	second_top = ft_pop_front(a);
	ft_push(a, top);
	ft_push(a, second_top);
	ft_enqueue(queue, (int)COMMAND_SA);
}

void ft_sb(ft_stack_t *b, ft_stack_t *queue)
{
	int	top;
	int	second_top;

	top = ft_pop_front(b);
	second_top = ft_pop_front(b);
	ft_push(b, top);
	ft_push(b, second_top);
	ft_enqueue(queue, (int)COMMAND_SB);
}

void ft_ss(ft_stack_t *a, ft_stack_t *b, ft_stack_t *queue)
{
	ft_sa(a, queue);
	ft_sb(b, queue);
	ft_enqueue(queue, (int)COMMAND_SS);
}

void ft_ra(ft_stack_t *a, ft_stack_t *queue)
{
	int	top;

	top = ft_pop_front(a);
	ft_enqueue(a, top);
	ft_enqueue(queue, (int)COMMAND_RA);
}

void ft_rb(ft_stack_t *b, ft_stack_t *queue)
{
	int	top;

	top = ft_pop_front(b);
	ft_enqueue(b, top);
	ft_enqueue(queue, (int)COMMAND_RB);
}

void ft_rr(ft_stack_t *a, ft_stack_t *b, ft_stack_t *queue)
{
	ft_ra(a, queue);
	ft_rb(b, queue);
	ft_enqueue(queue, (int)COMMAND_RR);
}

void ft_rra(ft_stack_t *a, ft_stack_t *queue)
{
	int	bottom;

	bottom = ft_pop_back(a);
	ft_push(a, bottom);
	ft_enqueue(queue, (int)COMMAND_RRA);
}

void ft_rrb(ft_stack_t *b, ft_stack_t *queue)
{
	int	bottom;

	bottom = ft_pop_back(b);
	ft_push(b, bottom);
	ft_enqueue(queue, (int)COMMAND_RRB);
}

void ft_rrr(ft_stack_t *a, ft_stack_t *b, ft_stack_t *queue)
{
	ft_rra(a, queue);
	ft_rrb(b, queue);
	ft_enqueue(queue, (int)COMMAND_RRR);
}

void ft_pa(ft_stack_t *a, ft_stack_t *b, ft_stack_t *queue)
{
	int top_b;

	top_b = ft_pop_front(b);
	ft_push(a, top_b);
	ft_enqueue(queue, (int)COMMAND_PA);
}

void ft_pb(ft_stack_t *a, ft_stack_t *b, ft_stack_t *queue)
{
	int top_a;

	top_a = ft_pop_front(a);
	ft_push(b, top_a);
	ft_enqueue(queue, (int)COMMAND_PB);
}

void ft_set_stack(arraylist_t *arraylist, ft_stack_t *stack, int is_stack_a)
{
	int	i;
	int *p;

	stack->front = NULL;
	stack->back = NULL;
	stack->size = 0;
	p = arraylist->pa_arr + arraylist->length - 1;
	i = 0;
	if (is_stack_a)
	{
		while (i < arraylist->length)
		{
			ft_push(stack, *p);
			p--;
			i++;
		}
	}
}

void ft_sort(ft_stack_t *a, ft_stack_t *b, ft_stack_t *pivot, ft_stack_t *pa_out_queue)
{
	if (a->size == 2)
	{
		swap_size_two_a(a, pa_out_queue);
	}
	else if (a->size == 3)
	{
		swap_size_three_a(a, pa_out_queue);
	}
	else
	{
		ft_split_a_to_b(a, b, pivot, pa_out_queue, a->size);
	}
}

void swap_size_two_a(ft_stack_t *stack, ft_stack_t *queue)
{
	int	top;
	int	sec_top;

	top = ft_pop_front(stack);
	sec_top = ft_pop_front(stack);

	if (top > sec_top)
	{
		ft_push(stack, sec_top);
		ft_push(stack, top);
		ft_sa(stack, queue);
	}
	else
	{
		ft_push(stack, sec_top);
		ft_push(stack, top);
	}
}

void swap_size_three_a(ft_stack_t *a, ft_stack_t *queue)
{
	int	arr[3];
	int	sort_order;

	sort_order = INT32_MAX;
	arr[0] = ft_pop_front(a);
	arr[1] = ft_pop_front(a);
	arr[2] = ft_pop_front(a);
	if (arr[0] > arr[1] && arr[0] < arr[2])
		sort_order = THREE_NUM_ORDER_CASE1;
	/* THREE_NUM_ORDER_CASE2만 stack b 일 때와 다르게 역정렬이 되어있을 경우 예 : 3 2 1 */
	else if (arr[0] > arr[1] && arr[1] > arr[2])
		sort_order = THREE_NUM_ORDER_CASE2;
	else if (arr[0] > arr[2] && arr[2] > arr[1])
		sort_order = THREE_NUM_ORDER_CASE3;
	else if (arr[0] < arr[2] && arr[2] < arr[1])
		sort_order = THREE_NUM_ORDER_CASE4;
	else if (arr[0] > arr[2] && arr[0] < arr[1])
		sort_order = THREE_NUM_ORDER_CASE5;
	swap_three_num_a(a, sort_order, queue);
}

void swap_three_num_a(ft_stack_t *stack, int sort_order, ft_stack_t *queue)
{
	if (sort_order == THREE_NUM_ORDER_CASE1)
	{
		ft_sa(stack, queue);
	}
	else if (sort_order == THREE_NUM_ORDER_CASE2)
	{
		ft_sa(stack, queue);
		ft_rra(stack, queue);
	}
	else if (sort_order == THREE_NUM_ORDER_CASE3)
	{
		ft_ra(stack, queue);
	}
	else if (sort_order == THREE_NUM_ORDER_CASE4)
	{
		ft_sa(stack, queue);
		ft_ra(stack, queue);
	}
	else if (sort_order == THREE_NUM_ORDER_CASE5)
	{
		ft_rra(stack, queue);
	}
}

void swap_size_two_b(ft_stack_t *stack, ft_stack_t *queue)
{
	int	top;
	int	sec_top;

	top = ft_pop_front(stack);
	sec_top = ft_pop_front(stack);

	if (top > sec_top)
	{
		ft_push(stack, sec_top);
		ft_push(stack, top);
	}
	else
	{
		ft_push(stack, sec_top);
		ft_push(stack, top);
		ft_sb(stack, queue);
	}
}

void	swap_size_three_b(ft_stack_t *b, ft_stack_t *queue)
{
	int	arr[3];
	int	sort_order;

	sort_order = INT32_MAX;
	arr[0] = ft_pop_front(b);
	arr[1] = ft_pop_front(b);
	arr[2] = ft_pop_front(b);
	if (arr[0] > arr[1] && arr[0] < arr[2])
		sort_order = THREE_NUM_ORDER_CASE1;
	/* THREE_NUM_ORDER_CASE2만 stack a 일 때와 다르게 정렬이 되어있을 경우 예 : 1 2 3 */
	else if (arr[0] < arr[1] && arr[1] < arr[2])
		sort_order = THREE_NUM_ORDER_CASE2;
	else if (arr[0] > arr[2] && arr[2] > arr[1])
		sort_order = THREE_NUM_ORDER_CASE3;
	else if (arr[0] < arr[2] && arr[2] < arr[1])
		sort_order = THREE_NUM_ORDER_CASE4;
	else if (arr[0] > arr[2] && arr[0] < arr[1])
		sort_order = THREE_NUM_ORDER_CASE5;
	swap_three_num_b(b, sort_order, queue);
}

void swap_three_num_b(ft_stack_t *stack, int sort_order, ft_stack_t *queue)
{
	if (sort_order == THREE_NUM_ORDER_CASE1)
	{
		
	}
	else if (sort_order == THREE_NUM_ORDER_CASE2)
	{
		
	}
	else if (sort_order == THREE_NUM_ORDER_CASE3)
	{
	
	}
	else if (sort_order == THREE_NUM_ORDER_CASE4)
	{
	
	}
	else if (sort_order == THREE_NUM_ORDER_CASE5)
	{
		
	}
}


void ft_split_a_to_b(ft_stack_t *a, ft_stack_t *b, ft_stack_t *pivots, ft_stack_t *queue, int stack_a_count)
{
	int	i;
	int	ra_count;
	int	pb_count;
	int	pivot;
	int	top;

	if (stack_a_count <= 1)
		return;
	if (stack_a_count == 2)
	{
		swap_size_two_a(a, queue);
		return;
	}
	if (stack_a_count == 3)
	{
		swap_size_three_a(a, queue);
		return;
	}
	i = 0;
	ra_count = 0;
	pb_count = 0;
	pivot = ft_pop_front(pivots);
	while (i < stack_a_count)
	{
		top = ft_peak(a);
		if (top > pivot)
		{
			ft_ra(a, queue);
			ra_count++;
		}
		else
		{
			ft_pb(a, b, queue);
			pb_count++;
		}
		i++;
	}
	i = 0;
	while (i < ra_count)
	{
		ft_rra(a, queue);
		i++;
	}
	ft_split_a_to_b(a, b, pivots, queue, ra_count);
	ft_split_b_to_a(a, b, pivots, queue, pb_count);
}

void ft_split_b_to_a(ft_stack_t *a, ft_stack_t *b, ft_stack_t *pivots, ft_stack_t *queue, int count)
{
	int	i;
	int	rb_count;
	int	pa_count;
	int	pivot;
	int	top;

	if (count == 1)
	{
		ft_pa(a, b, queue);
		return ;
	}
	if (count == 2)
	{
		swap_size_two_b(b, queue);
		ft_pa(a, b, queue);
		ft_pa(a, b, queue);
		return ;
	}
	if (count == 3)
	{
		swap_size_three_b(b, queue);
		return;
	}
	i = 0;
	rb_count = 0;
	pa_count = 0;
	pivot = ft_pop_front(pivots);
	while (i < count)
	{
		top = ft_peak(b);
		if (top > pivot)
		{
			ft_pa(a, b, queue);
			pa_count++;
		}
		else
		{
			ft_rb(b, queue);
			rb_count++;
		}
		i++;
	}
	i = 0;
	while (i < rb_count)
	{
		ft_rrb(b, queue);
		i++;
	}
	ft_split_a_to_b(a, b, pivots, queue, pa_count);
	ft_split_b_to_a(a, b, pivots, queue, rb_count);
}

void ft_put_queue(ft_stack_t *queue)
{
	linkedlist_t	*temp;
	int				i;
	int				res1;
	int				res2;
	int				is_even;
	
	i = 0;
	temp = queue->front;
	while (i < queue->size / 2)
	{
		res1 = temp->value;
		temp = temp->next;
		res2 = temp->value;
		temp = temp->next;

		if (res1 == COMMAND_SA && res2 == COMMAND_SB)

		else if ()
	}
	is_even = queue->size % 2 == 0;

	// 1 2 
	// 2
	// 1 2 3
	// 1
	// 1 2
}

void ft_put_command(int command)
{
	if (command == COMMAND_SA)
		write(1, "sa\n", 3);
	else if (command == COMMAND_SB)
		write(1, "sb\n", 3);
	else if (command == COMMAND_SS)
		write(1, "ss\n", 3);
	else if (command == COMMAND_RA)
		write(1, "ra\n", 3);
	else if (command == CO)
	
	COMMAND_RB,
	COMMAND_RR,
	COMMAND_RRA,
	COMMAND_RRB,
	COMMAND_RRR,
	COMMAND_PA,
	COMMAND_PB
}