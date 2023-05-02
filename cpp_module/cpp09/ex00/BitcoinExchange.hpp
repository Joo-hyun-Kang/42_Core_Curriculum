#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>

std::vector<std::pair<std::string, float> > readData();

void operateInput(std::vector<std::pair<std::string, float> > &data, char *input);

#endif