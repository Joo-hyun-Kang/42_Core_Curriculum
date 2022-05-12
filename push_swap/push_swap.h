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
int is_parse_argv_malloc(int argc, char **argv, arraylist_t *arraylist);