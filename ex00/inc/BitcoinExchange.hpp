/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 05:58:04 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/28 07:53:29 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <map>

# define BOLD "\e[1m"
# define ITALIC "\e[3m"
# define UNDERLINE "\e[4m"
# define RED "\e[91m"
# define GREEN "\e[92m"
# define YELLOW "\e[93m"
# define BLUE "\e[94m"
# define PURPLE "\e[95m"
# define CYAN "\e[96m"
# define INVERT "\e[90m\e[107m"
# define RESET "\e[0m"

class BitcoinExchange {
	private:
		std::map<std::string, double> data;

	public:
		// Constructors
		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange &_bitcoinexchange );

		// Destructor
		~BitcoinExchange( void );

		// Operator overloads
		BitcoinExchange &operator = ( const BitcoinExchange &_bitcoinexchange );

		// Getters

		// Setters

		// Methods
		void	exportDatabase();
		bool	isValidDate(std::string date);

		// Exceptions
};

#endif
