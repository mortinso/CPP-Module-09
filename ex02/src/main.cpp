/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:34 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/19 20:34:11 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int	main( int argc, char **argv ) {
	if (!isValid(argc, argv))
		return 1;

	PmergeMe	pm;

	try {
		pm.mergeInsert(argc, argv);
	}
	catch (std::exception &e) { std::cerr << e.what() << std::endl; }
}