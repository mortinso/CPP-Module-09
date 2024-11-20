/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 05:57:59 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/20 17:44:40 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange( void ) {
	// std::cout << "BitcoinExchange default constructor called" <<std::endl;
	importDatabase();
}

// Copy constructor
BitcoinExchange::BitcoinExchange( const BitcoinExchange &_bitcoinexchange ) {
	// std::cout << "BitcoinExchange copy constructor called" << std::endl;
	*this = _bitcoinexchange;
}

// Destructor
BitcoinExchange::~BitcoinExchange( void ) {
	// std::cout << "BitcoinExchange destructor called" <<std::endl;
}

// -----------------------------------Operators---------------------------------
// Copy assignment operator overload
BitcoinExchange& BitcoinExchange::operator = ( const BitcoinExchange &_bitcoinexchange ) {
	// std::cout << "BitcoinExchange copy assignment operator called" << std::endl;
	if (this != &_bitcoinexchange)
		*this = _bitcoinexchange;
	return (*this);
}

// -----------------------------------Methods-----------------------------------
// Copies information from the database to the map
void	BitcoinExchange::importDatabase( void ) {
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw (std::runtime_error("Failed to open database file"));

	std::string line;
	std::getline(file, line);
	if (file.eof() || line != "date,exchange_rate")
		throw (std::runtime_error("Invalid Database"));

	size_t	pos = 0;
	while (std::getline(file, line)) {
		pos = line.find(",");
		if (pos == std::string::npos)
			throw (std::runtime_error("Error when parsing Database"));
		data[line.substr(0, pos)] = std::atof(line.substr(pos + 1, std::string::npos).c_str());
	}
}

// Returns true if month has 31 days
bool	isBigMonth( int month ) {
	int	big_months[7] = {1, 3, 5, 7, 8, 10, 12};

	for (int i = 0; i < 7; i++) {
		if (month == big_months[i])
			return (true);
	}
	return (false);
}

// checks if date is valid
bool	isValidDate( std::string date ) {
	if (date.length() == 1 && date[0] == '|') {
		std::cerr << RED_H << "Error: missing date" << RESET << std::endl;
		return (false);
	}
	if ((date.length() != 10) || (date[4] != '-') || (date[7] != '-')) {
		std::cerr << RED_H << "Error: bad date => " << RESET << date << std::endl;
		return (false);
	}

	int year, month, day;
	char separator1;
	char separator2;
	std::string extra;
	bool valid = true;

	std::istringstream(date) >> year >> separator1 >> month >> separator2 >> day >> extra;
	// checks for invalid year, month and days
	if (year < 0 || !(month >= 1 && month <= 12) || !(day >= 1 && day <= 31) || extra[0])
		valid = false;

	// checks that month is in fact supposed to have 31 days
	else if (day == 31 && !isBigMonth(month))
		valid = false;

	// february checks, mainly leap year
	else if ((day > 29 && month == 2) || (day == 29 && month == 2 && (year % 4 != 0 || \
		(year % 4 == 0 && year % 100 == 0 && year % 400 != 0))))
		valid = false;

	if ( valid == false )
		std::cerr << RED_H << "Error: bad date => " << RESET << date << std::endl;

	return (valid);
}

// checks if value is valid
bool	isValidValue( std::string value ) {
	if (!value[0])
		std::cerr << RED_H << "Error: invalid value => " << RESET << value << std::endl;
	if (value[0] == '-')
		std::cerr << RED_H << "Error: not a positive value => " << RESET << value << std::endl;
	if (!value[0] || value[0] == '-')
		return false;

	int p_counter = 0;
	for (size_t i = 0; i < value.length(); i++) {
		if (value[i] == '.')
			p_counter++;
		if ((value[i] == '.' && p_counter > 1) || (!isdigit(value[i]) && value[i] != '.')) {
			std::cerr << RED_H << "Error: invalid value => " << RESET << value << std::endl;
			return false;
		}
	}

	double num = std::atof(value.c_str());
	if (num >= 0 && num <= 1000)
		return true;

	std::cerr << RED_H << "Error: value too large => " << RESET << value << std::endl;
	return false;
}

// Calculates the value and outputs the correct message
void	BitcoinExchange::calculate( std::string date, std::string value, bool full_info ) {
	std::map<std::string, double>::const_iterator it = data.lower_bound(date);
	if ( it != data.begin() && (it == data.end() || it->first != date))
		--it;

	std::string	db_date = it->first;
	double		exchange_rate = it->second;

	if (full_info == false)
		std::cout << date << " => " << value << " = " << (exchange_rate * std::atof(value.c_str())) << std::endl;
	else {
		std::cout << date << BLACK_H << " (" << db_date << ") " << RESET << " => ";
		std::cout << value << BLACK_H << " (" << exchange_rate << ") " << RESET;
		std::cout << " = " << (exchange_rate * std::atof(value.c_str())) << std::endl;
	}
}