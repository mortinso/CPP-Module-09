/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:23:39 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/19 16:47:19 by mortins-         ###   ########.fr       */
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

		RPN( const RPN &_rpn );
		RPN &operator = ( const RPN &_rpn );

		// Methods
		void	operate( char _operator );

	public:
		// Constructors
		RPN( void );

		// Destructor
		~RPN( void );

		// Methods
		void	doRPN( char *input );
};

#endif
