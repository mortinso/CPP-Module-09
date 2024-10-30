/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:23:39 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/30 04:33:05 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <algorithm>
# include <sstream>
# include <list>

# define BOLD "\e[1m"
# define ITALIC "\e[3m"
# define UNDERLINE "\e[4m"
# define RED "\e[91m"
# define GREEN "\e[92m"
# define YELLOW "\e[93m"
# define BLUE "\e[94m"
# define PURPLE "\e[95m"
# define CYAN "\e[96m"
# define INVERT "\e[90m\e[107m"
# define RESET "\e[0m"

class RPN {
	private:
		std::stack<int, std::list<int> > stck;

		// Methods
		void	operate( char _operator );

	public:
		// Constructors
		RPN( void );
		RPN( const RPN &_rpn );

		// Destructor
		~RPN( void );

		// Operator overloads
		RPN &operator = ( const RPN &_rpn );

		// Getters

		// Setters

		// Methods
		void	doRPN( char *input );

		// Exceptions
};

#endif
