/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:52 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/04 17:53:11 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

// Default constructor
PmergeMe::PmergeMe( void ) {
	// std::cout << "PmergeMe default constructor called" <<std::endl;
	straggler = 0;
}

// Copy constructor
PmergeMe::PmergeMe( const PmergeMe &_pmergeme ) {
	// std::cout << "PmergeMe copy constructor called" << std::endl;
	*this = _pmergeme;
}

// Destructor
PmergeMe::~PmergeMe( void ) {
	// std::cout << "PmergeMe destructor called" <<std::endl;
}

// -----------------------------------Operators---------------------------------
// Copy assignment operator overload
PmergeMe& PmergeMe::operator = ( const PmergeMe &_pmergeme ) {
	// std::cout << "PmergeMe copy assignment operator called" << std::endl;
	if (this != &_pmergeme) {
		// this->setValue(_pmergeme.getValue());
	}
	return (*this);
}

// -----------------------------------Getters-----------------------------------

// -----------------------------------Setters-----------------------------------

// -----------------------------------Methods-----------------------------------
// Saves input to the containers
void	PmergeMe::buildContainers( int argc, char **argv ) {
	isOdd = false;
	size = argc - 1;
	if (size % 2 != 0)
		isOdd = true;

	for (int i = 1; (i < argc && isOdd == false)|| i < argc - 1; i++) {
		vec.push_back(std::atoi(argv[i]));
		dq.push_back(std::atoi(argv[i]));
	}
	if (isOdd == true)
		straggler = std::atoi(argv[argc - 1]);

	printContainers();
}

// Prints the contents of both containers
void	PmergeMe::printContainers( void ) {
	std::cout << "Vector: { ";
	for (int i = 0; (i < size && isOdd == false)|| i < size - 1; i++)
		std::cout << vec[i] << ", ";
	std::cout << "}" << std::endl << "Deque: { ";
	for (int i = 0; (i < size && isOdd == false)|| i < size - 1; i++)
		std::cout << dq[i] << ", ";
	std::cout << "}" << std::endl;

	std::cout << "Straggler: " << this->straggler << std::endl;
}

// Sorts pairs for the vector
void PmergeMe::vectorSortPairs( void ) {
	for (int i = 0; (i < size && isOdd == false)|| i < size - 1; i += 2) {
		if (vec[i] > vec[i + 1]) {
			int	tmp = vec[i];
			vec[i] = vec[i + 1];
			vec[i + 1] = tmp;
		}
	}
}

// Sorts pairs for the deque
void PmergeMe::dequeSortPairs( void ) {
	for (int i = 0; (i < size && isOdd == false)|| i < size - 1; i += 2) {
		if (dq[i] > dq[i + 1]) {
			int	tmp = dq[i];
			dq[i] = dq[i + 1];
			dq[i + 1] = tmp;
		}
	}
}

// Binary search for a vector, returns the the number or the smaller one closest to it
int	PmergeMe::vectorBinarySearch( std::vector<int> &vec, int num ) {
	if (vec.size() < 1)
		throw (std::runtime_error("Error"));
	int	high = vec.size();
	int	low = 0;

	while (low <= high) {
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

// Binary search for a deque, returns the the number or the smaller one closest to it
int	PmergeMe::dequeBinarySearch( std::deque<int> &dq, int num ) {
	if (dq.size() < 1)
		throw (std::runtime_error("Error"));
	int	high = dq.size();
	int	low = 0;

	while (low <= high) {
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
		for (int j = i + 1; j < argc; j++) {
			if (atoi(argv[j]) == atoi(argv[i]))
				return true;
		}
	}
	return false;
}