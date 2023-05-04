#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>


std::vector<std::pair<std::string, float> > readFile();

void calculateInput(std::vector<std::pair<std::string, float> > &data, char *input);

#endif