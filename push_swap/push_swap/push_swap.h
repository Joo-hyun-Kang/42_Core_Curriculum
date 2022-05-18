#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

# define true (1)
# define false (0)

# define ARRAYLIST_BASIC_CAPACITY (10)

typedef struct arraylist {
	int* pa_arr;
	int length;
	int capacity;
} arraylist_t;

typedef struct linkedlist {
	int value;
	struct linkedlist *next;
} linkedlist_t;

typedef struct ft_stack {
	linkedlist_t *front;
	linkedlist_t *back;
	int	size;
} ft_stack_t;

enum COMMAND {
	COMMAND_SA,
	COMMAND_SB,
	COMMAND_SS,
	COMMAND_RA,
	COMMAND_RB,
	COMMAND_RR,
	COMMAND_RRA,
	COMMAND_RRB,
	COMMAND_RRR,
	COMMAND_PA,
	COMMAND_PB
};

enum THREE_NUM_ORDER {
	THREE_NUM_ORDER_CASE1,
	THREE_NUM_ORDER_CASE2,
	THREE_NUM_ORDER_CASE3,
	THREE_NUM_ORDER_CASE4,
	THREE_NUM_ORDER_CASE5
};

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

int add_arraylist(arraylist_t *arraylist, int value);
int is_arraylist_full(arraylist_t *arraylist);
int allocate_arraylist(arraylist_t *arraylist);
void free_arraylist(arraylist_t *arraylist);

void	get_optiml_pivot(arraylist_t *arraylist, ft_stack_t *pivot);
void	get_optimal_pivot_recursive(int *arr, ft_stack_t *stack, int start, int end);
int	is_overlap(int *arr, int length);
int	is_sorted(int *arr, int length);
void	quick_sort(int start, int end, int *arr);
int	divdie_and_conquer(int left, int right, int *nums);
void	swap(int *nums, int a, int b);

void	is_parse_argv_malloc(int argc, char **argv, arraylist_t *arraylist);
void	print_error_exit();

void ft_push(ft_stack_t *stack, int content);
void ft_enqueue(ft_stack_t *stack, int content);
int	ft_pop_front(ft_stack_t *stack);
int	ft_pop_back(ft_stack_t *stack);
int ft_peak(ft_stack_t *stack);
linkedlist_t *ft_remove(ft_stack_t *rootOrNull);
linkedlist_t	*ft_lstnew_malloc(int content);
void ft_free(ft_stack_t *stack);

void ft_sa(ft_stack_t *a, ft_stack_t *queue);
void ft_sb(ft_stack_t *b, ft_stack_t *queue);
void ft_ss(ft_stack_t *a, ft_stack_t *b, ft_stack_t *queue);
void ft_ra(ft_stack_t *a, ft_stack_t *queue);
void ft_rb(ft_stack_t *b, ft_stack_t *queue);
void ft_rr(ft_stack_t *a, ft_stack_t *b, ft_stack_t *queue);
void ft_rra(ft_stack_t *a, ft_stack_t *queue);
void ft_rrb(ft_stack_t *b, ft_stack_t *queue);
void ft_rrr(ft_stack_t *a, ft_stack_t *b, ft_stack_t *queue);
void ft_pa(ft_stack_t *a, ft_stack_t *b, ft_stack_t *queue);
void ft_pb(ft_stack_t *a, ft_stack_t *b, ft_stack_t *queue);

void ft_set_stack(arraylist_t *arraylist, ft_stack_t *stack, int is_stack_a);
void ft_sort(ft_stack_t *a, ft_stack_t *b, ft_stack_t *pivot, ft_stack_t *pa_out_queue);
void swap_size_two_a(ft_stack_t *stack, ft_stack_t *queue);
void swap_size_three_a(ft_stack_t *a, ft_stack_t *queue);
void swap_three_num_a(ft_stack_t *stack, int sort_order, ft_stack_t *queue);
void swap_size_two_b(ft_stack_t *stack, ft_stack_t *queue);
void swap_size_five(ft_stack_t *a, ft_stack_t *b, ft_stack_t *queue, int count);
int	get_max(ft_stack_t *stack);
int	get_min(ft_stack_t *stack);
void ft_split_a_to_b(ft_stack_t *a, ft_stack_t *b, ft_stack_t *pivots, ft_stack_t *queue, int stack_a_count);
void ft_split_b_to_a(ft_stack_t *a, ft_stack_t *b, ft_stack_t *pivots, ft_stack_t *queue, int count);

void ft_put_queue(ft_stack_t *queue);
void ft_put_command(int command);
