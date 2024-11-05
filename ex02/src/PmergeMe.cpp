/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:52 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/05 18:51:03 by mortins-         ###   ########.fr       */
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
}

// Prints the contents of both containers
void	PmergeMe::printContainers( void ) {
	std::cout << "Vector: { ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ", ";
	std::cout << "}" << std::endl << "Deque: { ";
	for (size_t i = 0; i < dq.size(); i++)
		std::cout << dq[i] << ", ";
	std::cout << "}" << std::endl;

	std::cout << "Straggler: " << this->straggler << std::endl;
}

// "Divides" the vector into pairs and sorts the pairs members
void	PmergeMe::vectorSortPairs( void ) {
	for (size_t i = 0; i < vec.size(); i += 2) {
		if (vec[i] > vec[i + 1]) {
			int	tmp = vec[i];
			vec[i] = vec[i + 1];
			vec[i + 1] = tmp;
		}
	}
}

// "Divides" the deque into pairs and sorts the pairs members
void	PmergeMe::dequeSortPairs( void ) {
	for (size_t i = 0; i < dq.size(); i += 2) {
		if (dq[i] > dq[i + 1]) {
			int	tmp = dq[i];
			dq[i] = dq[i + 1];
			dq[i + 1] = tmp;
		}
	}
}

// Builds new vector following steps 3 and 4
void	PmergeMe::vectorBuildNew( void ) {
	std::vector<int>	new_vec;

	// Adds the largest member of each pair to new_vec
	for (size_t i = 1; i < vec.size(); i += 2)
		new_vec.push_back(vec[i]);

	// Sorts new_vec
	std::sort(new_vec.begin(), new_vec.end());

	// Inserts at the start of new_vec the element that was paired with its first and smallest element
	for (size_t i = 0; i < vec.size(); i++) {
		if (vec[i] == new_vec.front()) {
			new_vec.insert(new_vec.begin(), vec[i - 1]);
			break ;
		}
	}

	// Removes from vec the numbers already in new_vec
	for (size_t i = 0; i < new_vec.size(); i++) {
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
			if (*it == new_vec[i]) {
				vec.erase(it);
				break;
			}
		}
	}

	for (size_t i = 0; i < new_vec.size(); i++)
		std::cout << new_vec[i] << " ";
	std::cout << std::endl;
	// Call next function that does the binary sorting with the jacobsthaal numbers
	std::cout << "VECTOR NEXT: Do binary sorting with the jacobsthaal numbers" << std::endl;
}

// Builds new deque following steps 3 and 4
void	PmergeMe::dequeBuildNew( void ) {
	std::deque<int>	new_dq;

	// Adds the largest member of each pair to new_dq
	for (size_t i = 1; i < dq.size(); i += 2)
		new_dq.push_back(dq[i]);

	// Sorts new_dq
	std::sort(new_dq.begin(), new_dq.end());

	// Inserts at the start of new_dq the element that was paired with its first and smallest element
	for (size_t i = 0; i < dq.size(); i++) {
		if (dq[i] == new_dq.front()) {
			new_dq.insert(new_dq.begin(), dq[i - 1]);
			break ;
		}
	}

	// Removes from dq the numbers already in new_dq
	for (size_t i = 0; i < new_dq.size(); i++) {
		for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); it++) {
			if (*it == new_dq[i]) {
				dq.erase(it);
				break;
			}
		}
	}

	for (size_t i = 0; i < new_dq.size(); i++)
		std::cout << new_dq[i] << " ";
	std::cout << std::endl;
	// Call next function that does the binary sorting with the jacobsthaal numbers
	std::cout << "DEQUE NEXT: Do binary sorting with the jacobsthaal numbers" << std::endl;
}

// Binary search for a vector, returns the index of the number or the largest one closest to it
int	PmergeMe::vectorBinarySearch( std::vector<int> &vec, int num ) {
	if (vec.size() < 1)
		throw (std::runtime_error("Error"));
	int	high = vec.size();
	int	low = 0;

	while (low != high) {
		int mid = (low + high) / 2;
		if (num < vec[mid])
			high = mid;
		else if (num > vec[mid])
			low = mid + 1;
		else {
			std::cerr << "Error: Same number" << std::endl;
			return mid;
		}
	}
	return (high);
}

// Binary search for a deque, returns the index of the number or the largest one closest to it
int	PmergeMe::dequeBinarySearch( std::deque<int> &dq, int num ) {
	if (dq.size() < 1)
		throw (std::runtime_error("Error"));
	int	high = dq.size();
	int	low = 0;

	while (low != high) {
		int mid = (low + high) / 2;
		if (num < dq[mid])
			high = mid;
		else if (num > dq[mid])
			low = mid + 1;
		else {
			std::cerr << "Error: Same number" << std::endl;
			return mid;
		}
	}
	return (high);
}

// -----------------------------------Exceptions--------------------------------

// -----------------------------------Checkers-------------------------------------
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

// Checks arguments for invalid characters
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

// Checks that there aren't any duplicate arguments
bool	hasDuplicates( int argc, char **argv ) {
	for (int i = 1; i < argc; i++) {
		for (int j = i + 1; j < argc; j++) {
			if (atoi(argv[j]) == atoi(argv[i]))
				return true;
		}
	}
	return false;
}

// -----------------------------------Utils-------------------------------------
// Returns the number of index n in jacobsthaal's sequence
int	jacobsNumber( int n ) {
	return ((pow(2, n) - pow(-1, n)) / 3);
}