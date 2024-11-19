/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 05:58:04 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/19 16:41:32 by mortins-         ###   ########.fr       */
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

		BitcoinExchange( const BitcoinExchange &_bitcoinexchange );
		BitcoinExchange &operator = ( const BitcoinExchange &_bitcoinexchange );

		// Methods
		void	importDatabase( void );
		double	getExchangeRate(std::string date);

	public:
		// Constructors
		BitcoinExchange( void );

		// Destructor
		~BitcoinExchange( void );

		// Methods
		void	calculate( std::string line, std::string date, double value );

};

bool	isValidDate( std::string date, std::string line );
bool	isValidValue( double value );

#endif
