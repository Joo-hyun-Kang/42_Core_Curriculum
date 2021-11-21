#include <stdio.h>

#define ALPHABET_COUNT (26);

void ft_print_reverse_alphabet(void)
{
	char alphabet;
  	size_t i;

	alphabet = 'z';
	i = ALPHABET_COUNT;
 	for (; i >= 1; i--) {
 		printf("%c", alphabet);
 		alphabet--;
 	}
}
