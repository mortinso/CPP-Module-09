/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:34 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/13 17:20:24 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int	main( int argc, char **argv ) {
	if (!isValid(argc, argv))
		return 1;

	PmergeMe	pm;

	std::cout << "Before: ";
	for (int i = 1; i < argc; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;

	pm.vectorMergeInsert(argc, argv);
	pm.dequeMergeInsert(argc, argv);
}
// Construct containers seperately
// Add sorted_vec and sorted_dq to the class
// Hub to call merge-insert for vector and deque seperately
// Count time it takes to sort for each type of container
// if size = 1, do nothing
// learn insert sort
// test invalid input better
//		test one argument
//		test already sorted
//		test ""
//		test just spaces

// https://en.wikipedia.org/wiki/Merge-insertion_sort
// https://en.wikipedia.org/wiki/Binary_search
// https://en.wikipedia.org/wiki/Jacobsthal_number