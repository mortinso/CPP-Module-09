/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:48 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/12 19:36:31 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <string.h>
# include <cmath>

# define BOLD		"\e[1m"
# define ITALIC		"\e[3m"
# define UNDERLINE	"\e[4m"
# define RED		"\e[91m"
# define GREEN		"\e[92m"
# define YELLOW		"\e[93m"
# define BLUE		"\e[94m"
# define PURPLE		"\e[95m"
# define CYAN		"\e[96m"
# define INVERT		"\e[90m\e[107m"
# define RESET		"\e[0m"

class PmergeMe {
	private:
		std::vector<std::pair<int, int> >	vec;
		std::deque<std::pair<int, int> >	dq;
		int									straggler;
		int									size;

		PmergeMe( const PmergeMe &_pmergeme );
		PmergeMe &operator = ( const PmergeMe &_pmergeme );

	public:
		// Constructors
		PmergeMe( void );

		// Destructor
		~PmergeMe( void );

		// Methods
		void	buildContainers( int argc, char **argv );
		void	printContainers( void );

		// Vector
		void	vectorSortPairs( void );
		void	vectorBuildNew( void );
		void	vectorJacobsthaal( std::vector<int> &sorted );
		int		vectorBinarySearch( std::vector<int> &vec, int num, int big );

		// Deque
		void	dequeSortPairs( void );
		void	dequeBuildNew( void );
		void	dequeJacobsthaal( std::deque<int> &sorted );
		int		dequeBinarySearch( std::deque<int> &dq, int num, int big );
};

// Checkers
bool	isValid( int argc, char **argv );
bool	isValidInput( int argc, char **argv );
bool	hasDuplicates( int argc, char **argv );

// Utils
int	jacobsNumber( int n );

#endif
