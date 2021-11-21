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
