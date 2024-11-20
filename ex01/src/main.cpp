/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:23:37 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/20 18:11:42 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int	main( int argc, char **argv ) {
	if (argc != 2) {
		std::cerr << RED_H << "Wrong number of arguments. Usage:" << std::endl << "./RPN <expression>" << std::endl;
		return 1;
	}
	try {
		RPN	rpn;
		rpn.doRPN(argv[1]);
	}
	catch (const std::exception &e) { std::cerr << RED_H << e.what() << RESET << std::endl;}
}

// to compare results, visit https://paodayag.dev/reverse-polish-notation-js-parser/