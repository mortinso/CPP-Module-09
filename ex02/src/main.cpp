/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:34 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/05 19:07:07 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int	main( int argc, char **argv ) {
	if (!isValid(argc, argv))
		return 1;

	std::cout << RED << "Need to turn the containers into containers of pairs of ints instead of just ints" << RESET << std::endl;
	/* PmergeMe	pm;

	pm.buildContainers(argc, argv);

	pm.vectorSortPairs();
	pm.dequeSortPairs();

	pm.printContainers();

	std::cout << std::endl;

	pm.vectorBuildNew();
	pm.dequeBuildNew();

	std::cout << std::endl;

	pm.printContainers(); */
	for (int i = 0; i < 11; i++)
		std::cout << jacobsNumber(i) << std::endl;
}
// maybe buildNew should return the new container object
// copy operator overload
// if size = 1, do nothing
// learn insert sort
// test invalid input better
// init vals on construction

// https://en.wikipedia.org/wiki/Merge-insertion_sort
// https://en.wikipedia.org/wiki/Binary_search
// https://en.wikipedia.org/wiki/Jacobsthal_number