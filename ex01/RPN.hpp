/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 13:51:02 by mforstho      #+#    #+#                 */
/*   Updated: 2023/07/28 17:48:00 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
# define RPN_HPP

#define NO_OPERATOR 0
#define ADD 1
#define SUBTRACT 2
#define MULTIPLY 3
#define DIVIDE 4

# include <iostream>
# include <stack>
# include <cctype>

class RPN {
	private:
		RPN(void);
		RPN(RPN const & src);
		virtual ~RPN(void);
		RPN & operator=(RPN const & src);

	public:
		static int	is_operator(int c);
		static bool	is_valid_input(std::string input);
		static int	do_rpn(std::string input);
};

#endif
