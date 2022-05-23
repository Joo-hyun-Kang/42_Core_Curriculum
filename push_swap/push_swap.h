/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:09:39 by jokang            #+#    #+#             */
/*   Updated: 2022/05/19 19:09:40 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define TRUE (1)
# define FALSE (0)
# define BASIC_CAPACITY (10)

typedef struct arraylist {
	int	*pa_arr;
	int	length;
	int	capacity;
}	t_arraylist;

typedef struct linkedlist {
	int					value;
	struct linkedlist	*next;
}	t_list;

typedef struct ft_stack {
	t_list	*front;
	t_list	*back;
	int		size;
}	t_stack;

typedef struct ft_member {
	t_stack	*a;
	t_stack	*b;
}	t_member;

enum e_COMMAND {
	COM_SA,
	COM_SB,
	COM_SS,
	COM_RA,
	COM_RB,
	COM_RR,
	COM_RRA,
	COM_RRB,
	COM_RRR,
	COM_PA,
	COM_PB
};

enum e_THREE_NUM_ORDER {
	THREE_NUM_ORDER_CASE1,
	THREE_NUM_ORDER_CASE2,
	THREE_NUM_ORDER_CASE3,
	THREE_NUM_ORDER_CASE4,
	THREE_NUM_ORDER_CASE5,
	THREE_NUM_ORDER_CASE6
};

char		**ft_do_split_malloc_or_null(const char *s, char c, char **out_res);
int			get_w_length(const char *str, char c);
int			is_charset(char str, char c);
void		do_free_malloc(char **res, char **tmp_res);
char		**ft_split(const char *s, char c);

int			ft_isspace(char ch);
int			ft_atoi(char *str, int *out_res);
int			ft_atoi_helper(char *str, int *out_res, int sign);
int			ft_isdigit(int c);

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		*ft_memcpy(void *dst, const void *src, size_t n);

int			add_arraylist(t_arraylist *arraylist, int value);
int			is_arraylist_full(t_arraylist *arraylist);
int			allocate_arraylist(t_arraylist *arraylist);
void		free_arraylist(t_arraylist *arraylist);

void		get_optiml_pivot(t_arraylist *arraylist, t_stack *pivot);
void		get_optimal_pivot_recur(int *arr, t_stack *stack, int s, int e);
int			is_overlap(int *arr, int length);
int			is_sorted(int *arr, int length);
void		quick_sort(int start, int end, int *arr);
int			ft_divdie_and_conquer(int left, int right, int *nums);
void		ft_swap(int *nums, int a, int b);

void		is_parse_argv_malloc(int argc, char **argv, t_arraylist *arraylist);
void		print_error_exit(void);

void		ft_push(t_stack *stack, int content);
void		ft_enqueue(t_stack *stack, int content);
int			ft_pop_front(t_stack *stack);
int			ft_pop_back(t_stack *stack);
int			ft_peak(t_stack *stack);
void		ft_free_spilt_str(char **pp);
void		exit_malloc_fail(void *p);

t_list		*ft_remove(t_stack *rootOrNull);
t_list		*ft_lstnew_malloc(int content);
void		ft_free(t_stack *stack);
void		ft_free_t_stack(t_stack **stack);

void		ft_sa(t_stack *a, t_stack *queue);
void		ft_sb(t_stack *b, t_stack *queue);
void		ft_ss(t_stack *a, t_stack *b, t_stack *queue);
void		ft_ra(t_stack *a, t_stack *queue);
void		ft_rb(t_stack *b, t_stack *queue);
void		ft_rr(t_stack *a, t_stack *b, t_stack *queue);
void		ft_rra(t_stack *a, t_stack *queue);
void		ft_rrb(t_stack *b, t_stack *queue);
void		ft_rrr(t_stack *a, t_stack *b, t_stack *queue);
void		ft_pa(t_stack *a, t_stack *b, t_stack *queue);
void		ft_pb(t_stack *a, t_stack *b, t_stack *queue);

void		ft_set_stack(t_arraylist *arraylist, t_stack **stack, int is_a);
void		ft_sort(t_member *member, t_stack *pivot, t_stack *pa_out_queue);
void		swap_size_two_a(t_stack *stack, t_stack *queue);
void		swap_size_three_a(t_stack *a, t_stack *queue);
void		swap_three_num_a(t_stack *stack, int sort_order, t_stack *queue);
void		swap_size_two_b(t_stack *stack, t_stack *queue);
void		swap_five(t_stack *a, t_stack *b, t_stack *queue, int count);
int			get_max(t_stack *stack);
int			get_min(t_stack *stack);
void		swap_hard_ab(t_stack *a, t_stack *b, t_stack *qu);
void		swap_hard_ab_help(t_stack *a, t_stack *b, int num, t_stack *qu);
void		swap_ab_help(t_stack *a, t_stack *b, int num, t_stack *qu);
void		swap_hard_ba(t_stack *a, t_stack *b, t_stack *qu);
void		swap_hard_ba_help(t_stack *a, t_stack *b, int num, t_stack *qu);
void		swap_ba_help(t_stack *a, t_stack *b, int num, t_stack *qu);
void		swap_ba_help_sec(t_stack *a, t_stack *b, int num, t_stack *qu);

void		ft_a_to_b(t_member *mem, t_stack *pvts, t_stack *qu, int cnt);
void		ft_b_to_a(t_member *mem, t_stack *pvts, t_stack *qu, int cnt);

void		ft_put_queue(t_stack *queue);
void		ft_put_queue_helper(int res1, int res2);
void		ft_put_command(int command);

void		ft_a_to_b_exit(t_member *member, t_stack *qu, int cnt);
void		ft_a_rra(t_member *member, t_stack *qu, int cnt);
void		ft_b_to_a_exit(t_member *member, t_stack *qu, int cnt);
void		ft_b_rrb(t_member *member, t_stack *qu, int cnt);

#endif /* PUSH_SWAP_H */