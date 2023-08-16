#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>

#define RED_TXT "\033[1;31m"
#define GREEN_TXT "\033[0;32m"
#define YELLOW_TXT "\033[0;33m"
#define BLUE_TXT "\033[0;34m"
#define ORANGE_TXT "\033[38;5;202m\033[22m"
#define DEFAULT_TXT "\033[1;39m"

struct DataSet {
	int date;
	double value;
};

class BitcoinExchange {
   private:
	std::ifstream _inputFile;
	std::ifstream _dbFile;
	std::string _inputFileName;
	std::string _dbFileName;
	std::map<int, double> _dbBitcoinPrice;

	BitcoinExchange();

	DataSet* getDataSet(std::string& line, char delimeter, bool shouldPrint);
	void saveDataBase(std::ifstream &stream, std::map<int, double>& db, char delimeter);

	std::map<int, double>::iterator findClosestDate(int date);

	std::string intDateToString(int date);
	void trimSpaces(std::string& str);
	bool onlySpaces(std::string& str);
	bool stringToDouble(std::string& str, double& value);
	bool isCorrectDateType(std::string& date);
	bool isInputDateValid(int year, int month, int day);
	bool isDigit(char c);

   public:
	BitcoinExchange(std::string inputFileName, std::string dbFileName = "data.csv");
	BitcoinExchange(const BitcoinExchange& rhs);
	BitcoinExchange & operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	void run();

	class OpenFailedException : public std::exception {
		virtual const char* what() const throw();
	};
};

#endif