/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:23:37 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/19 20:29:55 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int	main( int argc, char **argv ) {
	if (argc != 2) {
		std::cerr << "Wrong number of arguments. Usage:" << std::endl << "./RPN <expression>" << std::endl;
		return 1;
	}
	try {
		RPN	rpn;
		rpn.doRPN(argv[1]);
	}
	catch (const std::exception &e) { std::cerr << RED << e.what() << RESET << std::endl;}
	std::cout << RED << "Protect against division by zero" << std::endl;
	std::cout << "Maybe accept no spaces" << RESET << std::endl;
}

// to compare results, visit https://paodayag.dev/reverse-polish-notation-js-parser/