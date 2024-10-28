/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 05:57:59 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/28 07:59:43 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange( void ) {
	// std::cout << "BitcoinExchange default constructor called" <<std::endl;
	exportDatabase();
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

// -----------------------------------Getters-----------------------------------

// -----------------------------------Setters-----------------------------------

// -----------------------------------Methods-----------------------------------
void	BitcoinExchange::exportDatabase() {
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
		data[line.substr(0, pos)] = std::atof(line.substr(pos + 1, std::string::npos).c_str());
	}
	for (std::map<std::string, double>::const_iterator it = data.begin(); it != data.end(); ++it)
	{
    std::cout << it->first << " " << std::fixed << std::setprecision(2) << it->second << std::endl;
	}
}

// -----------------------------------Exceptions--------------------------------
