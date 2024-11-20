/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 05:58:04 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/20 16:58:12 by mortins-         ###   ########.fr       */
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
# include "colors.hpp"

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
		void	calculate( std::string line, std::string date, std::string value );

};

bool	isValidDate( std::string date, std::string line );
bool	isValidValue( std::string value );

#endif
