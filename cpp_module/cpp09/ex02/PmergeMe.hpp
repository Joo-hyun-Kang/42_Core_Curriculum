#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <deque>
#include <ctime>
#include <exception>

std::list<int>      mergeSortList(std::list<int> arr, int start, int end);
std::deque<int>		mergeSortDeque(std::deque<int> arr, int start, int end);
std::list<int>      insertionSortList(std::list<int> arr);
std::deque<int>		insertionSortDeque(std::deque<int> arr);

#endif