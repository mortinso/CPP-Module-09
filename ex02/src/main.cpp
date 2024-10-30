/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:34 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/30 07:27:45 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int	binarySearch(std::deque<int> &dq, int num)
{
	if (dq.size() < 1)
		throw (std::runtime_error("Error"));
	int	low = 0;
	int	high = dq.size();

	while (low <= high)
	{
		int mid = (low + high) / 2;
		std::cout << "mid = " << mid << std::endl;
		if (num <= dq[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (low != num)
		low--;
	return (low);
}

int	main( /* void */ int argc, char **argv ) {
	if (!isValid(argc, argv))
		return 1;
	std::deque<int> dq;

	for (int i = 0; i < 10; i++)
		dq.push_back(i * 2);

	for (int i = 0; i < 10; i++)
		std::cout << dq[i] << std::endl;

	for (int i = 0; i < 10; i++)
		std::cout << "i(" << i << ") " << dq[binarySearch(dq, i)] << std::endl;
}