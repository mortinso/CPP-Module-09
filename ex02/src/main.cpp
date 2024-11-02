/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:34 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/02 18:59:30 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int	main( /* void */ int argc, char **argv ) {
	if (!isValid(argc, argv))
		return 1;
	std::deque<int> dq;
	PmergeMe *pm = NULL;

	for (int i = 0; i < 10; i++)
		dq.push_back(i * 2);

	for (int i = 0; i < 10; i++)
		std::cout << dq[i] << std::endl;

	for (int i = 0; i < 10; i++)
		std::cout << "i(" << i << ") " << dq[pm->dequeBinarySearch(dq, i)] << std::endl;
}

// copy operator overload