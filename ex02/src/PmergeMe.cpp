/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:52 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/28 14:00:41 by mortins-         ###   ########.fr       */
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

// -----------------------------------Exceptions--------------------------------
