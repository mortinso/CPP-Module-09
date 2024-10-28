/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 05:57:59 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/28 10:41:09 by mortins-         ###   ########.fr       */
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
	if (this != &_bitcoinexchange) {
		*this = _bitcoinexchange;
	}
	return (*this);
}

// -----------------------------------Methods-----------------------------------
void	BitcoinExchange::importDatabase( void ) {
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw (std::runtime_error("Failed to open database file"));

	std::string line;
	std::getline(file, line);
	if (file.eof() || line != "date,exchange_rate")
		throw (std::runtime_error("Invalid Database"));

	size_t	pos = 0;
	while (std::getline(file, line))
	{
		pos = line.find(",");
		if (pos == std::string::npos)
			throw (std::runtime_error("Error when parsing Database"));
		data[line.substr(0, pos)] = std::atof(line.substr(pos + 1, std::string::npos).c_str());
	}
	/* for (std::map<std::string, double>::const_iterator it = data.begin(); it != data.end(); ++it)
		std::cout << it->first << " " << std::fixed << std::setprecision(2) << it->second << std::endl; */
}

bool	isBigMonth( int month ) {
	int	big_months[7] = {1, 3, 5, 7, 8, 10, 12};

	for (int i = 0; i < 7; i++) {
		if (month == big_months[i])
			return (true);
	}
	return (false);
}

bool	isValidDate( std::string date, std::string line ) {
	if ((date.length() != 10) || (date[4] != '-') || (date[7] != '-'))
		return (false);

	int year, month, day;
	char separator1;
	char separator2;
	bool valid = true;

	std::istringstream(date) >> year >> separator1 >> month >> separator2 >> day;

	if (year < 0 || !(month >= 1 && month <= 12) || !(day >= 1 && day <= 31))
		valid = false;

	else if (day == 31 && !isBigMonth(month))
		valid = false;

	else if ((day > 29 && month == 2) || (day == 29 && month == 2 && (year % 4 != 0 || \
		(year % 4 == 0 && year % 100 == 0 && year % 400 != 0))))
		valid = false;

	if ( valid == false )
		std::cerr << RED << "Error: bad date => " << RESET << line.substr(0, line.find('|')) << std::endl;

	return (valid);
}


bool	isValidValue( double value ) {
	if (value < 0)
	{
		std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
		return false;
	}
	else if (value > 1000)
	{
		std::cerr << RED << "Error: too large a number." << RESET << std::endl;
		return false;
	}
	return true;
}
