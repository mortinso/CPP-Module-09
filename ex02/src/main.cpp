/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:34 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/04 21:18:48 by mortins-         ###   ########.fr       */
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
// maybe buildNew should return the new container object
// copy operator overload
// if size = 1, do nothing
// learn insert sort
// test invalid input better
// init vals on construction