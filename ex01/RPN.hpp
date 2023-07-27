/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 13:51:02 by mforstho      #+#    #+#                 */
/*   Updated: 2023/07/27 15:05:29 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
# define RPN_HPP

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
};

#endif
