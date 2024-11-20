/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 05:56:51 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/20 16:57:02 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int	main( int argc, char **argv ) {
	if (argc != 2)
	{
		std::cerr << RED_H << "Wrong number of arguments" << RESET << std::endl;
		return 1;
	}
	try {
		std::ifstream file(argv[1]);
		if (!file.is_open())
			throw (std::runtime_error("Failed to open input file"));

		std::string line;
		std::getline(file, line);
		if (file.eof() || line != "date | value")
			throw (std::runtime_error("Invalid/Missing header"));

		BitcoinExchange	btc;

		std::string date;
		char separator;
		std::string value;
		while (std::getline(file, line))
		{
			if (line == "")
				continue ;

			std::istringstream istring(line);

			date = "";
			separator = 0;
			value = -1;
			istring >> date >> separator >> value;


			if (separator == 0 || separator != '|') {
				std::cerr << RED_H << "Error: bad input => " << RESET << line << std::endl;
				continue ;
			}
			else if (!isValidDate(date, line))
				continue ;
			else if (!isValidValue(value))
				continue ;

			btc.calculate(line, date, value);
		}

	}
	catch (const std::exception &e) { std::cerr << RED_H << e.what() << RESET << std::endl; }
	std::cout << RED_H << "Check all errors on input.txt" << std::endl;
	std::cout << "Maybe add exchange rate and found date to output, or at least an option to do it" << RESET << std::endl;
}