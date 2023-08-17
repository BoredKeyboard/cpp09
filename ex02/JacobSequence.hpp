/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   JacobSequence.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 16:31:00 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/17 14:38:00 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef JS_HPP
# define JS_HPP

# include <cstddef>

struct JacobSequence {
	size_t _latest_value;
	size_t _latest_p2;

	JacobSequence(void);
	size_t next(void);
};

#endif
