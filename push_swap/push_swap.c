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

static int	ft_isspace(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v'
		|| ch == '\f' || ch == '\r' || ch == ' ')
	{
		return (1);
	}
	return (0);
}

/*
* 후조건
* - int 범위 문자열은 숫자로 반환
* - int 범위 넘어서는 숫자는 -1 반환
* - 숫자가 아닌 경우 0 반환
*/

int	ft_atoi(const char *str, int *out_res)
{
	int					sign;
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
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += *str - '0';
		//Int 표현 범위 –2,147,483,648 ~ 2,147,483,647
		if (result > 2147483647 && sign == 1)
			return (false);
		if (result > 2147483648 && sign == -1)
			return (false);
		str++;
	}
	if (result == 0) 
	{
		return (false);
	}
	*out_res = (int)(sign * result);
	return (true);
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

////////////////////////////////////

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
    
    assert(allocate_arraylist(&pa_arraylist) == true);
    is_parse_argv_malloc(argc, argv, &pa_arraylist);

	// 예외처리 4: 중복된 숫자가 들어왔을 때 Error 출력하고 종료
	// 예외처리 5: 정렬된 거 일 때 아무것도 출력하지 않고 그냥 종료
	for (int i = 0; i < pa_arraylist.length; i++) {
		printf("%d\n", pa_arraylist.pa_arr[i]);
	}
}

// 여기서 입력값 전부 방어한다

// 함수의 후조건
// 1. 입력이 잘못 들어오는 경우 -1 return
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