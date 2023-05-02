#include "BitcoinExchange.hpp"

void errorMessage(std::string str) {
	std::cout << str << std::endl;
}

void errorMessageDate(std::string str, std::string date) {
	std::cout << str << date << std::endl;
}

std::vector<std::pair<std::string, float> > readData() {
	std::vector<std::pair<std::string, float> > data;
	std::ifstream readFile("data.csv");
	if (!readFile) {
		std::cout << "Error: data.csv doesn't exist." << std::endl;
		exit(1);
	}
	std::string input;
	std::getline(readFile, input);
	while (std::getline(readFile, input)) {
		std::stringstream ss(input);
		std::string date, rate;
		std::getline(ss, date, ',');
		std::getline(ss, rate);
		try {
			data.push_back(std::make_pair(date, static_cast<float>(atof(rate.c_str()))));
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			exit(1);
		}
	}
	readFile.close();
	return data;
}

bool isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}

bool checkDate(std::string date) {
	std::istringstream iss(date);
	int year, month, day;
	char sep1, sep2;

	if (date.length() != 10 || date.substr(5, 1) == "+" || date.substr(6, 1) == "+" || date.substr(7, 1) == "+" || date.substr(8, 1) == "+" || date.substr(9, 1) == "+") {
		return false;
	}
	iss >> year >> sep1 >> month >> sep2 >> day;
	if (iss.fail() || year < 2009 || (year == 2009 && month == 1 && day < 2) || (2022 < year) || (year == 2022 && month > 3) || month < 0 || month > 12 || day < 1 || day > 31 || sep1 != '-' || sep2 != '-')
		return false;
	if (isLeapYear(year) && month == 2 && day > 29) {
		return false;
	} else if (month == 2 && day > 28)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
		return false;
	return true;
}

float getRatio(std::vector<std::pair<std::string, float> > &data, std::string date) {
	float prevRatio = data.begin()->second;
	int year, month, day;

	try {
		year = atoi(date.substr(0, 4).c_str());
		month = atoi(date.substr(5, 2).c_str());
		day = atoi(date.substr(8, 2).c_str());
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	
	return -1;
}
for (std::vector<std::pair<std::string, float> >::iterator iter = data.begin(); iter != data.end(); iter++) {
	if (iter->first == date.substr(0, 10)) {
		return iter->second;
	} else if (year < atoi((iter->first).substr(0, 4).c_str())) {
		return prevRatio;
	} else if (year == atoi((iter->first).substr(0, 4).c_str())) {
		if (month < atoi((iter->first).substr(5, 2).c_str()))
			return prevRatio;
		else if (month == atoi((iter->first).substr(5, 2).c_str()) && day < atoi((iter->first).substr(8, 2).c_str()))
			return prevRatio;
	}
	prevRatio = iter->second;
}
if (year == 2022)
	return (prevRatio);
return -1;

}

bool checkValue(std::string value) {
float v;

for (size_t i = 0; i < value.length(); i++) {
	if (value[i] == '-' || value[i] == '+') {
		errorMessage("Error: a weird number");
		return false;
	}
}
try {
	v = static_cast<float>(atof(value.c_str()));
	if (v < 0) {
		errorMessage("Error: not a positive number");
		return false;
	} else if (v > 1000) {
		errorMessage("Error: too large a number");
		return false;
	}
} catch (std::exception &e) {
	std::cout << e.what() << std::endl;
	return false;
}
return true;

}

void operateInput(std::vector<std::pair<std::string, float> > &data, char *input) {
std::ifstream readFile(input);
if (!readFile) {
errorMessage("Error: file not exist");
exit(1);
}
std::string columnName;
std::getline(readFile, columnName);
if (columnName.compare("date | value")) {
errorMessage("Error: bad column argument");
exit(1);
}
std::string inputString;
while (std::getline(readFile, inputString)) {
char sep;
std::string date;
std::string value;
std::istringstream iss(inputString);
float ratio;

	if (!(iss >> date >> sep >> value) || sep != '|')
		errorMessageDate("Error: bad input => ", date);
	else if (!checkDate(date))
		errorMessageDate("Error: bad input => ", date);
	else if (!checkValue(value)) {}
	else {
		ratio = getRatio(data, date);
		if (ratio != -1) {
			std::cout << std::fixed;
			std::cout.precision(2);
			std::cout << date << " => " << value << " = " << static_cast<float>(atof(value.c_str())) * getRatio(data, date) << std::endl;
		} else {
			std::cout << "Error: cannot find the date" << std::endl;
		}
	}
}
readFile.close();
}