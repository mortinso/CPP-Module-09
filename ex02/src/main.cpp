/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:34 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/12 18:52:44 by mortins-         ###   ########.fr       */
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

	// std::vector<int> vec;

	// for (int i = 3; i < 9; i++)
	// 	vec.push_back(i);

	// std::cout << "{ ";
	// for (size_t i = 0; i < vec.size(); i++)
	// 	std::cout << vec[i] << " | ";
	// std::cout << "}" << std::endl;

	// std::cout << "When lower, binarySearch returns: " << pm.vectorBinarySearch(vec, 1, 8) << std::endl;

	// vec.insert(vec.begin(), 1);

}
// Hub to call merge-insert for vector and deque seperately
// maybe buildNew should return the new container object
// Count time it takes to sort for each type of container
// if size = 1, do nothing
// learn insert sort
// test invalid input better
// init vals on construction

// https://en.wikipedia.org/wiki/Merge-insertion_sort
// https://en.wikipedia.org/wiki/Binary_search
// https://en.wikipedia.org/wiki/Jacobsthal_number