/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:48 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/30 07:29:27 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
#include <string.h>

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

class PmergeMe {
	private:
		std::deque<int>		dq;
		std::vector<int>	vect;
		bool				isOdd;
		int					straggler;

		PmergeMe( void );
	public:
		// Constructors
		PmergeMe( const PmergeMe &_pmergeme );

		// Destructor
		~PmergeMe( void );

		// Operator overloads
		PmergeMe &operator = ( const PmergeMe &_pmergeme );

		// Getters

		// Setters

		// Methods
		int	vectorBinarySearch(std::vector<int> &vect, int num);
		int	dequeBinarySearch(std::deque<int> &dq, int num);

		// Exceptions
};

bool	isValid( int argc, char **argv );
bool	isValidInput( int argc, char **argv );
bool	hasDuplicates( int argc, char **argv );

#endif
