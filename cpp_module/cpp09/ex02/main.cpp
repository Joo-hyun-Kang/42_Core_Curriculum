#include "PmergeMe.hpp"

size_t	get_cnt(int element) {
	size_t i = 0;
	for (; element > 0; i++) {
		element /= 10;
	}
	return i;
}

int	main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Error: it needs arguments" << std::endl;
		exit(1);
	}

	std::vector<int>	v;
	std::deque<int>		d;

	try {
		for (int i = 1; i < argc; i++) {
			for (int j = 0; j < (int)strlen(argv[i]); j++) {
				if (!isdigit(argv[i][j])) {
					std::cout << "Error: invalid argument" << std::endl;
					exit(1);
				}
			}
			int	element = atoi(argv[i]);
			if (get_cnt(element) != strlen(argv[i])) {
				std::cout << "Error" << std::endl;
				exit(1);
			}
			if (element <= 0) {
				std::cout << "Error: not a positive argument" << std::endl;
				exit(1);
			}
			v.push_back(element);
			d.push_back(element);
		}
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		exit(1);
	}

	std::cout << "<deque> Before: " << std::endl;
	for (std::deque<int>::iterator iter = d.begin(); iter != d.end(); iter++) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
	std::cout << "<vector> Before: " << std::endl;
	for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

    std::clock_t startVector = std::clock();
	v = mergeSortVector(v, 0, v.size());
    std::clock_t endVector = std::clock();
	std::clock_t	startDeque = std::clock();
	d = mergeSortDeque(d, 0, d.size());
	std::clock_t	endDeque = std::clock();
	std::cout << "<vector> after" << std::endl;
	for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	std::cout << "<deque> after" << std::endl;
	for (std::deque<int>::iterator iter = d.begin(); iter != d.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << v.size() << " elements with Vector sort: " << (double)(endVector - startVector) << " us" << std::endl;
	std::cout << "Time to process a range of " << d.size() << " elements with Deque sort: " << (double)(endDeque - startDeque) << " us" << std::endl;
}
