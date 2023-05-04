#include "BitcoinExchange.hpp"

std::vector<std::pair<std::string, float> > readFile() {
	std::vector<std::pair<std::string, float> > db;

	std::ifstream fin;
	fin.open("data.csv", std::ios_base::in);

	if (fin.is_open()) {
		std::cout << "Counldn't open data.csv" << std::endl;
		exit(1);
	}

	std::string readline;
	std::getline(fin, readline);
	while (!fin.eof()) {
		std::getline(fin, readline);
		
		std::stringstream buffer(readline);

		std::string date, rate;
		std::getline(buffer, date, ',');
		std::getline(buffer, rate);

		try 
		{
			db.push_back(std::make_pair(date, static_cast<float>(atof(rate.c_str()))));
		} catch (std::exception &e) 
		{
			std::cout << e.what() << std::endl;
			exit(1);
		}
	}

	fin.close();

	return db;
}

void errorMessage(std::string str) {
	std::cout << str << std::endl;
}

void printErrorWithData(std::string str, std::string date) {
	std::cout << str << date << std::endl;
}

bool isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}

bool checkDate(std::string date) {
	std::stringstream buffer(date);
	int year, month, day;
	char sep1, sep2;

	if (date.length() != 10)
	{
		return false;
	}

    for (int i = 0; i < date.length(); ++i) {
        if (i == 4 || i == 7) {
            if (date[i] != '-') {
                return false;
            }
        } else {
            if (!isdigit(date[i])) {
                return false;
            }
        }
    }

	buffer >> year >> sep1 >> month >> sep2 >> day;
	if (buffer.fail() || year < 0 || year > 9999 || month < 0 || month > 12 || day < 1 || day > 31 || sep1 != '-' || sep2 != '-')
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

void calculateInput(std::vector<std::pair<std::string, float> > &db, char *input) {
	std::ifstream fin;
	fin.open(input, std::ios_base::in);

	if (fin.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		exit(1);
	}

	std::string header;
	std::getline(fin, header);
	if (header != "date | value") {
		errorMessage("Error: invaild format.");
		exit(1);
	}

	std::string content;
	while (std::getline(fin, content)) 
	{
		std::stringstream buffer(content);
		std::string date;
		std::string value;
		char seperator;
		float ratio;

		if (!(buffer >> date >> seperator >> value) || seperator != '|')
			printErrorWithData("Error: bad input => ", date);
		else if (!checkDate(date))
			printErrorWithData("Error: bad input => ", date);
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