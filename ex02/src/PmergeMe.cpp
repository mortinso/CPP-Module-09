/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:52 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/07 18:44:06 by mortins-         ###   ########.fr       */
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
	if (this != &_pmergeme)
		*this = _pmergeme;
	return (*this);
}

// -----------------------------------Methods-----------------------------------
/* // Saves input to the containers
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
} */

// Saves input to the containers
void	PmergeMe::buildContainers( int argc, char **argv ) {
	isOdd = false;
	size = argc - 1;
	if (size % 2 != 0)
		isOdd = true;

	for (int i = 1; (i < argc - 1 && isOdd == false)|| i < argc - 2; i += 2) {
		std::pair<int, int> tmp;
		tmp.first = std::atoi(argv[i]);
		tmp.second = std::atoi(argv[i + 1]);
		vec.push_back(tmp);
		dq.push_back(tmp);
	}
	if (isOdd == true)
		straggler = std::atoi(argv[argc - 1]);
}

// Prints the contents of both containers
void	PmergeMe::printContainers( void ) {
	std::cout << "Vector: { ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i].first << ", " << vec[i].second << " | ";
	std::cout << "}" << std::endl << "Deque: { ";
	for (size_t i = 0; i < dq.size(); i++)
		std::cout << dq[i].first << ", " << dq[i].second << " | ";
	std::cout << "}" << std::endl;

	std::cout << "Straggler: " << this->straggler << std::endl;
}

// -----------------------------------Vector------------------------------------
// Divides the vector into pairs and sorts the pairs in ascending order and their members in descending order
void	PmergeMe::vectorSortPairs( void ) {
	// Sort members descendingly
	for (size_t i = 0; i < vec.size(); i++) {
		if (vec[i].first < vec[i].second) {
			int	tmp = vec[i].first;
			vec[i].first = vec[i].second;
			vec[i].second = tmp;
		}
	}

	// Sort pairs ascendantly by first member
	std::sort(vec.begin(), vec.end());

	// Sort members ascendantly
	for (size_t i = 0; i < vec.size(); i++) {
		if (vec[i].first > vec[i].second) {
			int	tmp = vec[i].first;
			vec[i].first = vec[i].second;
			vec[i].second = tmp;
		}
	}
}

// Builds new vector following steps 3 and 4
void	PmergeMe::vectorBuildNew( void ) {
	std::vector<int>	new_vec;

	// Adds the largest member of each pair to new_vec
	for (size_t i = 0; i < vec.size(); i++)
		new_vec.push_back(vec[i].second);

	// Inserts at the start of new_vec the element that was paired with its first and smallest element
	new_vec.insert(new_vec.begin(), vec[0].first);

	// Removes it
	vec.erase(vec.begin());

	// Call next function that does the binary sorting with the jacobsthaal numbers
	std::cout << "VECTOR NEXT: Do binary sorting with the jacobsthaal numbers" << std::endl;
}

// My spin on binary search, returns the closest number larger than 'num'
// Errors if 'big' is not a member of 'vec' or if 'num' is already in 'vec'
int	PmergeMe::vectorBinarySearch( std::vector<int> &vec, int num, int big ) {
	if (vec.size() < 1)
		throw (std::runtime_error("Error"));
	int	high = 0;
	int	low = 0;

	while ((size_t)high < vec.size() && vec[high] != big)
		high++;

	if (vec[high] != big)
		throw (std::runtime_error("Error: Binary Search failed"));

	while (low != high) {
		int mid = (low + high) / 2;
		if (num < vec[mid])
			high = mid;
		else if (num > vec[mid])
			low = mid + 1;
		else
			throw (std::runtime_error("Error: Binary Search encountered a duplicate number"));
	}
	return (high);
}

// -----------------------------------Deque-------------------------------------
// Divides the deque into pairs and sorts the pairs in ascending order and their members in descending order
void	PmergeMe::dequeSortPairs( void ) {
	// Sort members descendingly
	for (size_t i = 0; i < dq.size(); i++) {
		if (dq[i].first < dq[i].second) {
			int	tmp = dq[i].first;
			dq[i].first = dq[i].second;
			dq[i].second = tmp;
		}
	}

	// Sort pairs ascendantly by first member
	std::sort(dq.begin(), dq.end());

	// Sort members ascendantly
	for (size_t i = 0; i < dq.size(); i++) {
		if (dq[i].first > dq[i].second) {
			int	tmp = dq[i].first;
			dq[i].first = dq[i].second;
			dq[i].second = tmp;
		}
	}
}

// Builds new deque following steps 3 and 4
void	PmergeMe::dequeBuildNew( void ) {
	std::deque<int>	new_dq;

	// Adds the largest member of each pair to new_dq
	for (size_t i = 0; i < dq.size(); i++)
		new_dq.push_back(dq[i].second);

	// Inserts at the start of new_vec the element that was paired with its first and smallest element
	new_dq.insert(new_dq.begin(), dq[0].first);

	// Removes it
	dq.erase(dq.begin());

	// Call next function that does the binary sorting with the jacobsthaal numbers
	std::cout << "DEQUE NEXT: Do binary sorting with the jacobsthaal numbers" << std::endl;
}

// My spin on binary search, returns the closest number larger than 'num'
// Errors if 'big' is not a member of 'dq' or if 'num' is already in 'dq'
int	PmergeMe::dequeBinarySearch( std::deque<int> &dq, int num, int big ) {
	if (vec.size() < 1)
		throw (std::runtime_error("Error"));
	int	high = 0;
	int	low = 0;

	while ((size_t)high < dq.size() && dq[high] != big)
		high++;

	if (dq[high] != big)
		throw (std::runtime_error("Error: Binary Search failed"));

	while (low != high) {
		int mid = (low + high) / 2;
		if (num < dq[mid])
			high = mid;
		else if (num > dq[mid])
			low = mid + 1;
		else
			throw (std::runtime_error("Error: Binary Search encountered a duplicate number"));
	}
	return (high);
}

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