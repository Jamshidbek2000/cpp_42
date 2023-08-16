#include "../include/BitcoinExchange.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS / DESTRUCTOR                    //
// ************************************************************************** //

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string inputFileName, std::string dbFileName) {
	_inputFileName = inputFileName;
	_dbFileName = dbFileName;
	_inputFile.open(inputFileName.c_str());
	_dbFile.open(dbFileName.c_str());

	if (!_inputFile) throw OpenFailedException();
	if (!_dbFile) throw OpenFailedException();
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs) {
	_inputFileName = rhs._inputFileName;
	_dbFileName = rhs._dbFileName;

	if (!rhs._inputFile.is_open()) _inputFile.open(_inputFileName.c_str());
	if (!rhs._dbFile.is_open()) _dbFile.open(_dbFileName.c_str());

	if (!_inputFile) throw OpenFailedException();
	if (!_dbFile) throw OpenFailedException();
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs) {
		_inputFileName = rhs._inputFileName;
		_dbFileName = rhs._dbFileName;

		if (!rhs._inputFile.is_open()) _inputFile.open(_inputFileName.c_str());
		if (!rhs._dbFile.is_open()) _dbFile.open(_dbFileName.c_str());

		if (!_inputFile) throw OpenFailedException();
		if (!_dbFile) throw OpenFailedException();
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	if (_inputFile.is_open()) _inputFile.close();
	if (_dbFile.is_open()) _dbFile.close();
}

// ************************************************************************** //
//                               MEMBER FUNCTIONS                             //
// ************************************************************************** //

void BitcoinExchange::run() {
	std::string line;
	DataSet *dataSet;
	std::map<int, double>::iterator it;

	saveDataBase(_dbFile, _dbBitcoinPrice, ',');
	if (_dbBitcoinPrice.size() == 0) {
		std::cout << "DataBase is empty" << std::endl;
		return;
	}
	std::getline(_inputFile, line);
	while (std::getline(_inputFile, line)) {
		dataSet = NULL;
		dataSet = getDataSet(line, '|', true);
		if (dataSet != NULL) {
			it = findClosestDate(dataSet->date);
			if (it != _dbBitcoinPrice.end())
				std::cout << dataSet->date << " => " << dataSet->value << " = "
						  << dataSet->value * it->second << std::endl;
		}
		delete dataSet;
	}
}

void BitcoinExchange::saveDataBase(std::ifstream &stream, std::map<int, double> &db,
								   char delimeter) {
	std::string line;
	DataSet *dataSet;
	int date;
	double value;

	while (std::getline(stream, line)) {
		dataSet = NULL;
		dataSet = getDataSet(line, delimeter, false);
		if (dataSet) {
			date = dataSet->date;
			value = dataSet->value;
			db.insert(std::make_pair(date, value));
		}
		delete dataSet;
	}
}

DataSet *BitcoinExchange::getDataSet(std::string &line, char delimeter, bool shouldPrint) {
	std::string date;
	std::string value;
	double tmp;
	DataSet *dataSet = NULL;

	if (line.empty() || onlySpaces(line)) return NULL;	// if empty || onlySpaces => NULL
	trimSpaces(line);

	if (std::count(line.begin(), line.end(), delimeter) != 1) {
		if (shouldPrint) std::cout << "Error: bad input => " << line << std::endl;
		return NULL;  // if there is not one commma => NULL
	}

	date = line.substr(0, line.find_first_of(delimeter));  // get date part
	trimSpaces(date);

	if (isCorrectDateType(date) == false) {
		if (shouldPrint) std::cout << "Error: bad input => " << date << std::endl;
		return NULL;
	}

	if (date.size() + 3 == line.size()) {
		if (shouldPrint)
			std::cout << "Error: bad input." << intDateToString(dataSet->date) << std::endl;
		return NULL;  // if there is no value
	}

	dataSet = new DataSet();
	stringToDouble(date, tmp);
	dataSet->date = static_cast<int>(tmp);

	if (!isInputDateValid(dataSet->date / 10000, dataSet->date % 10000 / 100,
						  dataSet->date % 100)) {
		if (shouldPrint) {
			std::cout << "Error: bad input. " << intDateToString(dataSet->date) << std::endl;
		}
		delete dataSet;
		return NULL;
	}

	value = line.substr(line.find_first_of(delimeter) + 1, line.size());  // get the part after date
	trimSpaces(value);
	if (stringToDouble(value, dataSet->value) == false) {
		if (shouldPrint) std::cout << "Error: not a number." << std::endl;
		delete dataSet;
		return NULL;
	}
	if (dataSet->value < 0) {
		if (shouldPrint) std::cout << "Error: not a positive number." << std::endl;
		delete dataSet;
		return NULL;
	}
	if (shouldPrint && dataSet->value > 1000) {
		if (shouldPrint) std::cout << "Error: too large a number." << std::endl;
		delete dataSet;
		return NULL;
	}
	return dataSet;
}

std::map<int, double>::iterator BitcoinExchange::findClosestDate(int date) {
	std::map<int, double>::iterator it = _dbBitcoinPrice.lower_bound(date);

	if (it == _dbBitcoinPrice.begin()) return it;
	if (it == _dbBitcoinPrice.end()) return --it;
	if (it->first > date) --it;
	return it;
}

bool BitcoinExchange::isCorrectDateType(std::string &date) {
	int i = 0;
	size_t pos;
	bool result = true;

	if (date.size() == 10) {
		for (; i < 4; i++) {
			if (result == true && isDigit(date.at(i)) == false) result = false;
		}
		if (date.at(i++) != '-') result = false;
		for (; i < 7; i++) {
			if (result == true && isDigit(date.at(i)) == false) result = false;
		}
		if (result == true && date.at(i++) != '-') result = false;
		for (; i < 10; i++) {
			if (result == true && isDigit(date.at(i)) == false) result = false;
		}
	} else
		return false;
	pos = date.find('-');
	while (pos != std::string::npos) {
		date.replace(pos, 1, "");
		pos = date.find('-');
	}
	return true;
}

std::string BitcoinExchange::intDateToString(int date) {
	char buffer[11];  // Assuming the maximum length of the resulting string is 10 characters
	std::sprintf(buffer, "%d-%02d-%02d", date / 10000, (date / 100) % 100, date % 100);
	return std::string(buffer);
}

bool BitcoinExchange::stringToDouble(std::string &str, double &value) {
	std::istringstream iss(str);
	return (iss >> value) && (iss.eof());
}

void BitcoinExchange::trimSpaces(std::string &str) {
	str = str.substr(str.find_first_not_of(' '), str.find_last_not_of(' ') + 1);
}

bool BitcoinExchange::onlySpaces(std::string &str) {
	if (str.find_first_not_of(' ') == std::string::npos) return true;
	return false;
}

bool BitcoinExchange::isInputDateValid(int year, int month, int day) {
	// Check if year is a leap year
	bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	// Check if month is valid
	if (month < 1 || month > 12) {
		return false;
	}

	// Check if day is valid
	if (day < 1 || day > 31) {
		return false;
	}

	// Check specific cases for February
	if (month == 2) {
		if (isLeap && day > 29) {
			return false;  // Leap year, February has 29 days
		} else if (!isLeap && day > 28) {
			return false;  // Non-leap year, February has 28 days
		}
	}

	// Check months with 30 days
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;  // These months have 30 days

	// Input date is valid
	return true;
}

bool BitcoinExchange::isDigit(char c) {
	if (c < '0' || c > '9') return false;
	return true;
}

// ************************************************************************** //
//                               NESTED CLASSES                               //
// ************************************************************************** //

const char *BitcoinExchange::OpenFailedException::what() const throw() {
	return "Error: could not open file.\n";
}