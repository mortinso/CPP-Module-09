/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:34 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/12 20:39:52 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int	main( int argc, char **argv ) {
	if (!isValid(argc, argv))
		return 1;

	PmergeMe	pm;

	pm.buildContainers(argc, argv);

	pm.vectorSortPairs();
	pm.dequeSortPairs();

	pm.printContainers();

	std::cout << std::endl;

	pm.vectorBuildNew();
	pm.dequeBuildNew();

	std::cout << std::endl;

	pm.printContainers();
}
// Construct containers seperately
// Add sorted_vec and sorted_dq to the class
// Hub to call merge-insert for vector and deque seperately
// Count time it takes to sort for each type of container
// if size = 1, do nothing
// learn insert sort
// test invalid input better

// https://en.wikipedia.org/wiki/Merge-insertion_sort
// https://en.wikipedia.org/wiki/Binary_search
// https://en.wikipedia.org/wiki/Jacobsthal_number