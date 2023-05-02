#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <exception>

std::vector<int>	mergeSortVector(std::vector<int> arr, int start, int end);
std::vector<int>	insertionSortVector(std::vector<int> arr);
std::deque<int>		mergeSortDeque(std::deque<int> arr, int start, int end);
std::deque<int>		insertionSortDeque(std::deque<int> arr);

#endif