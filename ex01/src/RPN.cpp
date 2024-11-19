/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:23:34 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/19 16:56:58 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

// Default constructor
RPN::RPN( void ) {
	// std::cout << "RPN default constructor called" <<std::endl;
}

// Copy constructor
RPN::RPN( const RPN &_rpn ) {
	// std::cout << "RPN copy constructor called" << std::endl;
	stck = _rpn.stck;
}

// Destructor
RPN::~RPN( void ) {
	// std::cout << "RPN destructor called" <<std::endl;
}

// -----------------------------------Operators---------------------------------
// Copy assignment operator overload
RPN& RPN::operator = ( const RPN &_rpn ) {
	// std::cout << "RPN copy assignment operator called" << std::endl;
	if (this != &_rpn) {
		stck = _rpn.stck;
	}
	return (*this);
}

// -----------------------------------Methods-----------------------------------
void	RPN::doRPN( char *input ) {
	size_t i = 0;
	while (input && input[i] != '\0')
	{
		while (input[i] == ' ')
			i++;

		if (input[i] == 0)
			break;

		// if number, push to stack
		if (input[i] >= '0' && input[i] <= '9')
		{
			if (input[i + 1] != 0 && input[i + 1] != ' ')
				throw(std::runtime_error("Error: No space between arguments"));
			stck.push(input[i] - '0');
		}

		// if operator, call operate
		else if (input[i] == '+' | input[i] == '-' | input[i] == '*' | input[i] == '/')
		{
			if (input[i + 1] != 0 && input[i + 1] != ' ')
				throw(std::runtime_error("Error: No space between arguments"));
			operate(input[i]);
		}

		else
			throw(std::runtime_error("Error: Invalid argument"));

		i++;
	}
	if (stck.size() != 1)
		throw(std::runtime_error("Error: Not enough operators"));

	std::cout << stck.top() << std::endl;
}
// operate:
//	pops top 2;
//	operates on them;
//	pushes result to stack
void	RPN::operate( char _operator ) {
	if (stck.size() < 2)
		throw(std::runtime_error("Error: Not enough operands before operator"));

	int	a = stck.top();
	stck.pop();

	int	b = stck.top();
	stck.pop();

	int	c;

	switch (_operator) {
		case '+':
			c = b + a;
			break;

		case '-':
			c = b - a;
			break;

		case '*':
			c = b * a;
			break;

		case '/':
			c = b / a;
			break;
	}
	// std::cout << b << " " << _operator << " " << a << " = " << c << std::endl;
	stck.push(c);
}
