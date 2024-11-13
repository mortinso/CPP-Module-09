/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:52 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/13 17:24:04 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

// Default constructor
PmergeMe::PmergeMe( void ) {
	// std::cout << "PmergeMe default constructor called" <<std::endl;
	straggler = -1;
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
// Calls merge-insert for each container and times it, outputting the messages expected by the subject
void	PmergeMe::mergeInsert( int argc, char **argv ) {
	//time variables here

	std::cout << "Before: ";
	for (int i = 1; i < argc; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;

	size = argc - 1;

	// start timing vector
	// call vector merge insert
	// stop timing vector

	// start timing deque
	// call deque merge insert
	// stop timing deque

	// output after

	// output time for vector
	// output time for deque
}


// Saves input to the containers
void	PmergeMe::buildContainers( int argc, char **argv ) {
	size = argc - 1;

	for (int i = 1; i < argc - (size % 2) - 1; i += 2) {
		std::pair<int, int> tmp;
		tmp.first = std::atoi(argv[i]);
		tmp.second = std::atoi(argv[i + 1]);
		vec.push_back(tmp);
		dq.push_back(tmp);
	}
	if (size % 2 != 0)
		straggler = std::atoi(argv[argc - 1]);
}

// Prints the contents of both containers
void	PmergeMe::printContainers( void ) {
	std::cout << "Vector: { ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i].first << ", " << vec[i].second << " | ";
	std::cout << "}" << std::endl;
	std::cout << "Deque: { ";
	for (size_t i = 0; i < dq.size(); i++)
		std::cout << dq[i].first << ", " << dq[i].second << " | ";
	std::cout << "}" << std::endl;

	std::cout << "Straggler: " << this->straggler << std::endl;
}

// -----------------------------------Vector------------------------------------
// Merge Insert sort for vector
void	PmergeMe::vectorMergeInsert( int argc, char **argv ) {
	std::cout << RED << "Remove line under this message" << RESET << std::endl;
	size = argc - 1;

	vectorBuild(argc, argv);

	vectorSortPairs();

	vectorLarge();

	vectorJacobsthaal();

	std::cout << RED << "Remove this: " << RESET;
	for (size_t i = 0; i < sorted_vec.size(); i++)
		std::cout << sorted_vec[i] << " ";
	std::cout << std::endl;
}

// Creates the vector with its members
void	PmergeMe::vectorBuild( int argc, char **argv ) {
	for (int i = 1; i < argc - (size % 2) - 1; i += 2) {
		std::pair<int, int> tmp;
		tmp.first = std::atoi(argv[i]);
		tmp.second = std::atoi(argv[i + 1]);
		vec.push_back(tmp);
	}
	if (size % 2 != 0)
		straggler = std::atoi(argv[argc - 1]);
}

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
void	PmergeMe::vectorLarge( void ) {
	// Adds the largest member of each pair to new_vec
	for (size_t i = 0; i < vec.size(); i++)
		sorted_vec.push_back(vec[i].second);

	// Inserts at the start of new_vec the element that was paired with its first and smallest element
	sorted_vec.insert(sorted_vec.begin(), vec[0].first);

	// Removes it
	vec.erase(vec.begin());
}

// Sorts members of vec into sorted_vec using binary search and jacobsthaals sequence
void	PmergeMe::vectorJacobsthaal( void ) {
	for (int jacob_index = 3; vec.size() > 0; jacob_index++) {
		// Set group_size
		size_t group_size = jacobsNumber(jacob_index) - jacobsNumber(jacob_index - 1);
		if (group_size > vec.size())
			group_size = vec.size();

		// Add members from vec to sorted_vec, starting at vec[group_size - 1] and finishing at vec[i]
		for (int i = (int)group_size - 1; i >= 0; i--) {
			int place = vectorBinarySearch(vec[i].first, vec[i].second);
			sorted_vec.insert(sorted_vec.begin() + place, vec[i].first);
		}

		// Erase members already added to sorted_vec
		for (size_t i = 0; i < group_size; i++)
			vec.erase(vec.begin());
	}

	if (straggler >= 0) {
		if (straggler > sorted_vec.back())
			sorted_vec.push_back(straggler);
		else {
			int place = vectorBinarySearch(straggler, sorted_vec.back());
			sorted_vec.insert(sorted_vec.begin() + place, straggler);
		}
	}
}

// My spin on binary search, returns the closest number larger than 'num'
// Errors if 'big' is not a member of sorted_vec or if 'num' is already in sorted_vec
int	PmergeMe::vectorBinarySearch( int num, int big ) {
	if (vec.size() < 1)
		throw (std::runtime_error("Error"));
	int	high = 0;
	int	low = 0;

	while ((size_t)high < sorted_vec.size() && sorted_vec[high] != big)
		high++;

	if (sorted_vec[high] != big)
		throw (std::runtime_error("Error: Binary Search failed"));

	while (low != high) {
		int mid = (low + high) / 2;
		if (num < sorted_vec[mid])
			high = mid;
		else if (num > sorted_vec[mid])
			low = mid + 1;
		else
			throw (std::runtime_error("Error: Binary Search encountered a duplicate number"));
	}
	return (high);
}

// -----------------------------------Deque-------------------------------------
// Merge Insert sort for deque
void	PmergeMe::dequeMergeInsert( int argc, char **argv ) {
	std::cout << RED << "Remove line under this message" << RESET << std::endl;
	size = argc - 1;

	dequeBuild(argc, argv);

	dequeSortPairs();

	dequeLarge();

	dequeJacobsthaal();

	std::cout << RED << "Remove this: " << RESET;
	for (size_t i = 0; i < sorted_dq.size(); i++)
		std::cout << sorted_dq[i] << " ";
	std::cout << std::endl;
}

// Creates the deque with its members
void	PmergeMe::dequeBuild( int argc, char **argv ) {
	for (int i = 1; i < argc - (size % 2) - 1; i += 2) {
		std::pair<int, int> tmp;
		tmp.first = std::atoi(argv[i]);
		tmp.second = std::atoi(argv[i + 1]);
		dq.push_back(tmp);
	}
	if (size % 2 != 0)
		straggler = std::atoi(argv[argc - 1]);
}

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
void	PmergeMe::dequeLarge( void ) {
	// Adds the largest member of each pair to sorted_dq
	for (size_t i = 0; i < dq.size(); i++)
		sorted_dq.push_back(dq[i].second);

	// Inserts at the start of sorted_dq the element that was paired with its first and smallest element
	sorted_dq.insert(sorted_dq.begin(), dq[0].first);

	// Removes it
	dq.erase(dq.begin());
}

// Sorts members of dq into sorted_dq using binary search and jacobsthaals sequence
void	PmergeMe::dequeJacobsthaal( void ) {
	for (int jacob_index = 3; dq.size() > 0; jacob_index++) {
		// Set group_size
		size_t group_size = jacobsNumber(jacob_index) - jacobsNumber(jacob_index - 1);
		if (group_size > dq.size())
			group_size = dq.size();

		// Add members from dq to sorted_dq, starting at dq[group_size - 1] and finishing at dq[i]
		for (int i = (int)group_size - 1; i >= 0; i--) {
			int place = dequeBinarySearch(dq[i].first, dq[i].second);
			sorted_dq.insert(sorted_dq.begin() + place, dq[i].first);
		}

		// Erase members already added to sorted_dq
		for (size_t i = 0; i < group_size; i++)
			dq.erase(dq.begin());
	}

	if (straggler >= 0) {
		if (straggler > sorted_dq.back())
			sorted_dq.push_back(straggler);
		else {
			int place = dequeBinarySearch(straggler, sorted_dq.back());
			sorted_dq.insert(sorted_dq.begin() + place, straggler);
		}
	}
}

// My spin on binary search, returns the closest number larger than 'num'
// Errors if 'big' is not a member of sorted_dq or if 'num' is already in sorted_dq
int	PmergeMe::dequeBinarySearch( int num, int big ) {
	if (dq.size() < 1)
		throw (std::runtime_error("Error"));
	int	high = 0;
	int	low = 0;

	while ((size_t)high < sorted_dq.size() && sorted_dq[high] != big)
		high++;

	if (sorted_dq[high] != big)
		throw (std::runtime_error("Error: Binary Search failed"));

	while (low != high) {
		int mid = (low + high) / 2;
		if (num < sorted_dq[mid])
			high = mid;
		else if (num > sorted_dq[mid])
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