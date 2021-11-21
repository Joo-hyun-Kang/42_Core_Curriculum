#include <stdio.h>

int get_fibonacci_recursive(int index);

int main(void)
{
	printf("0: %d\n", get_fibonacci_recursive(0));
	printf("1: %d\n", get_fibonacci_recursive(1));
	printf("2: %d\n", get_fibonacci_recursive(2));
	printf("3: %d\n", get_fibonacci_recursive(3));
	printf("4: %d\n", get_fibonacci_recursive(4));
	printf("5: %d\n", get_fibonacci_recursive(5));
}

int get_fibonacci_recursive(int index)
{
	if (index < 0) {
		return -1;
	}
	if (index == 0) {
		return 0;
	}
	if (index == 1) {
		return 1;
	}

	return get_fibonacci_recursive(index - 1) + get_fibonacci_recursive(index - 2);
}
