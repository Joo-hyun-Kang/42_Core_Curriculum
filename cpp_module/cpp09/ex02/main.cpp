#include "PmergeMe.hpp"

size_t	getPlaceValue(int parsedValue) {
	size_t i = 0;
	while (parsedValue > 0) 
	{
		parsedValue /= 10;
		i++;
	}
	return i;
}

int	main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Error: invaild argument" << std::endl;
		exit(1);
	}

	std::list<int>		list;
	std::deque<int>		deque;


	// 자료구조에 데이터 삽입
	try 
	{
		for (int i = 1; i < argc; i++) 
		{
			for (int j = 0; j < (int)strlen(argv[i]); j++) 
			{
				if (!isdigit(argv[i][j])) 
				{
					std::cout << "Error: invalid argument" << std::endl;
					exit(1);
				}
			}

			int	parsedValue = atoi(argv[i]);

			if (getPlaceValue(parsedValue) != strlen(argv[i])) 
			{
				std::cout << "Error" << std::endl;
				exit(1);
			}

			if (parsedValue <= 0) 
			{
				std::cout << "Error: not a positive argument" << std::endl;
				exit(1);
			}

			list.push_back(parsedValue);
			deque.push_back(parsedValue);
		}
	} 
	catch (std::exception &e) 
	{
		std::cout << "Error: " << e.what() << std::endl;
		exit(1);
	}


	// 초기값 출력
	std::cout << "<deque> Before: " << std::endl;
	for (std::deque<int>::iterator iter = deque.begin(); iter != deque.end(); iter++) 
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	std::cout << "<list> Before: " << std::endl;
	for (std::list<int>::iterator iter = list.begin(); iter != list.end(); iter++) 
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;


	// 시간 측정하고 머지 소트
    std::clock_t startList = std::clock();
	list = mergeSortList(list, 0, list.size());
    std::clock_t endList = std::clock();
	
	std::clock_t	startDeque = std::clock();
	deque = mergeSortDeque(deque, 0, deque.size());
	std::clock_t	endDeque = std::clock();


	// 정렬 후 출력
	std::cout << "<list> after" << std::endl;
	for (std::list<int>::iterator iter = list.begin(); iter != list.end(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	std::cout << "<deque> after" << std::endl;
	for (std::deque<int>::iterator iter = deque.begin(); iter != deque.end(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;


	// 시간 출력
	std::cout << "Time to process a range of " << list.size() << " elements with List sort: " << (double)(endList - startList) << " us" << std::endl;
	std::cout << "Time to process a range of " << deque.size() << " elements with Deque sort: " << (double)(endDeque - startDeque) << " us" << std::endl;
}
