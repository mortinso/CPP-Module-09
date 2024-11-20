/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 05:58:04 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/20 17:24:35 by mortins-         ###   ########.fr       */
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

	public:
		// Constructors
		BitcoinExchange( void );

		// Destructor
		~BitcoinExchange( void );

		// Methods
		void	calculate( std::string date, std::string value, bool full_info );

};

bool	isValidDate( std::string date );
bool	isValidValue( std::string value );

#endif
