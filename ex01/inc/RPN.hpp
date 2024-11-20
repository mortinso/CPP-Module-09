/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:23:39 by mortins-          #+#    #+#             */
/*   Updated: 2024/11/20 18:11:51 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <algorithm>
# include <sstream>
# include <list>
# include "colors.hpp"

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
