#include "PmergeMe.hpp"

std::deque<int>	insertionSortDeque(std::deque<int> arr) 
{
	int tmp;

	for (int i = 1; i < (int)arr.size(); i++) 
	{
		for (int j = i; j > 0; j--) 
		{
			if (arr[j - 1] > arr[j]) 
			{
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}

	return arr;
}

std::deque<int>	mergeSortDeque(std::deque<int> arr, int start, int end) 
{
	if (end - start < 32)
	{
		return insertionSortDeque(arr);
	}

	int	mid = (end + start) / 2;	
	std::deque<int>	arrLeft;
	std::deque<int>	arrRight;

	for (int i = 0; i < mid; i++)
	{
		arrLeft.push_back(arr[i]);
	}

	for (int i = mid; i < end; i++)
	{
		arrRight.push_back(arr[i]);
	}

	arrLeft = mergeSortDeque(arrLeft, 0, arrLeft.size());
	arrRight = mergeSortDeque(arrRight, 0, arrRight.size());

	std::deque<int>	mergedArr;
	int	left = 0, right = 0;

	while (left < (int)arrLeft.size() && right < (int)arrRight.size()) 
	{
		if (arrLeft[left] < arrRight[right])
		{
			mergedArr.push_back(arrLeft[left++]);
		}
		else
		{
			mergedArr.push_back(arrRight[right++]);
		}
	}
	for (; left < (int)arrLeft.size(); left++)
	{
		mergedArr.push_back(arrLeft[left]);
	}
	for (; right < (int)arrRight.size(); right++)
	{
		mergedArr.push_back(arrRight[right]);
	}
	
	return mergedArr;
}

std::list<int>	insertionSortList(std::list<int> arr) 
{
    std::list<int>::iterator it_i, it_j;

    for (it_i = ++arr.begin(); it_i != arr.end(); ++it_i) {
        for (it_j = it_i; it_j != arr.begin(); --it_j) {
            std::list<int>::iterator it_j_prev = it_j;
            --it_j_prev;

            if (*it_j_prev > *it_j) {
                std::iter_swap(it_j, it_j_prev);
            }
        }
    }
    return arr;
}

std::list<int>	mergeSortList(std::list<int> arr, int start, int end) 
{
	if (end - start < 32)
	{
		return insertionSortList(arr);
	}

	int	mid = (end + start) / 2;	
    std::list<int> arrLeft;
    std::list<int> arrRight;

 	std::list<int>::iterator it = arr.begin();
    for (int i = 0; i < start; ++i) 
	{
        ++it;
    }
	
    for (int i = 0; i < mid; ++i) 
	{
        arrLeft.push_back(*it);
        ++it;
    }

    for (int i = mid; i < end; ++i) 
	{
        arrRight.push_back(*it);
        ++it;
    }

    arrLeft = mergeSortList(arrLeft, 0, static_cast<int>(arrLeft.size()));
    arrRight = mergeSortList(arrRight, 0, static_cast<int>(arrRight.size()));

	std::list<int> mergedArr;
    std::list<int>::iterator left = arrLeft.begin();
    std::list<int>::iterator right = arrRight.begin();

    while (left != arrLeft.end() && right != arrRight.end()) 
	{
        if (*left < *right) 
		{
            mergedArr.push_back(*left);
            ++left;
        } else 
		{
            mergedArr.push_back(*right);
            ++right;
        }
    }

    while (left != arrLeft.end()) 
	{
        mergedArr.push_back(*left);
        ++left;
    }
    while (right != arrRight.end()) 
	{
        mergedArr.push_back(*right);
        ++right;
    }

    return mergedArr;
}