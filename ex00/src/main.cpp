/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 05:56:51 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/28 07:27:17 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int	main( int argc, char **argv ) {
	if (argc != 2)
	{
		std::cerr << RED << "Wrong number of arguments" << RESET << std::endl;
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

		while (std::getline(file, line))
		{
			std::istringstream istring(line);
			std::string date;
			float value;
			char separator;

			if (line == "")
				continue ;
			istring >> date >> separator >> value;


		}

	}
	catch (const std::exception &e) { std::cerr << RED << e.what() << RESET << std::endl; }
}