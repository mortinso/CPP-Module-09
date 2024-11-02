/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:52 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/02 19:01:10 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

// Default constructor
PmergeMe::PmergeMe( void ) {
	std::cout << "PmergeMe default constructor called" <<std::endl;
}

// Copy constructor
PmergeMe::PmergeMe( const PmergeMe &_pmergeme ) {
	std::cout << "PmergeMe copy constructor called" << std::endl;
	*this = _pmergeme;
}

// Destructor
PmergeMe::~PmergeMe( void ) {
	std::cout << "PmergeMe destructor called" <<std::endl;
}

// -----------------------------------Operators---------------------------------
// Copy assignment operator overload
PmergeMe& PmergeMe::operator = ( const PmergeMe &_pmergeme ) {
	std::cout << "PmergeMe copy assignment operator called" << std::endl;
	if (this != &_pmergeme) {
		// this->setValue(_pmergeme.getValue());
	}
	return (*this);
}

// -----------------------------------Getters-----------------------------------

// -----------------------------------Setters-----------------------------------

// -----------------------------------Methods-----------------------------------
int	PmergeMe::vectorBinarySearch(std::vector<int> &vec, int num)
{
	if (vect.size() < 1)
		throw (std::runtime_error("Error"));
	int	low = 0;
	int	high = vect.size();

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (num <= vec[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (vec[low] > num)
		low--;
	return (low);
}

int	PmergeMe::dequeBinarySearch(std::deque<int> &dq, int num) {
	if (dq.size() < 1)
		throw (std::runtime_error("Error"));
	int	low = 0;
	int	high = dq.size();

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (num <= dq[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (dq[low] > num)
		low--;
	return (low);
}

// -----------------------------------Exceptions--------------------------------

// -----------------------------------Utils-------------------------------------
bool	isValid( int argc, char **argv ) {
	if (argc < 2) {
		std::cerr << "Wrong number of arguments" << std::endl;
		return false;
	}
	if (!isValidInput(argc, argv)) {
		std::cerr << "Invalid input" << std::endl;
		return false;
	}
	if (hasDuplicates(argc, argv)) {
		std::cerr << "No duplicate inputs allowed" << std::endl;
		return false;
	}
	return true;
}

bool	isValidInput( int argc, char **argv ) {
	for (int i = 1; i < argc; i++) {
		if (!argv[i] || !argv[i][0] || atoi(argv[i]) < 0)
			return false;
		if (strlen(argv[i]) > 1 && argv[i][0] == '+')
			i++;
		for (size_t j = 0; argv[i][j]; j++) {
			if (!isdigit(argv[i][j])) {
				return false;
			}
		}
	}
	return true;
}

bool	hasDuplicates( int argc, char **argv ) {
	for (int i = 1; i < argc; i++) {
		for (size_t j = i + 1; argv[j] != NULL; i++) {
			if (atoi(argv[j]) == atoi(argv[i]))
				return true;
		}
	}
	return false;
}