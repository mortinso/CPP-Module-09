/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:48 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/20 18:17:55 by mortins-         ###   ########.fr       */
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
# include <ctime>
# include "colors.hpp"

# define INVERT BLACK BG_WHITE_H

template <typename T>
bool	isSorted( T begin, T const &end ) {
	for(long temp = -1; begin != end ;begin++) {
		if (static_cast<long>(*begin) < temp)
			return (false);
		temp = *begin;
	}
	return (true);
}

class PmergeMe {
	private:
		std::vector<std::pair<int, int> >	vec;
		std::vector<int>					sorted_vec;
		int									vec_time;
		std::deque<std::pair<int, int> >	dq;
		std::deque<int>						sorted_dq;
		int									dq_time;
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
		void	mergeInsert( int argc, char **argv );

		// Vector
		void	vectorMergeInsert( int argc, char **argv );
		void	vectorBuild( int argc, char **argv );
		void	vectorSortPairs( void );
		void	vectorLarge( void );
		void	vectorJacobsthaal( void );
		int		vectorBinarySearch( int num, int big );

		// Deque
		void	dequeMergeInsert( int argc, char **argv );
		void	dequeBuild( int argc, char **argv );
		void	dequeSortPairs( void );
		void	dequeLarge( void );
		void	dequeJacobsthaal( void );
		int		dequeBinarySearch( int num, int big );
};

// Checkers
bool	isValid( int argc, char **argv );
bool	isValidInput( int argc, char **argv );
bool	hasDuplicates( int argc, char **argv );
bool	isSorted( int argc, char **argv );

// Utils
int	jacobsNumber( int n );

#endif
