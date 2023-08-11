/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   JS.cpp                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 16:33:26 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/11 16:37:02 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "JS.hpp"

JS::JS(void) {
}

JS::JS(JS const & src) {
}

JS::~JS(void) {
}

JS & JS::operator=(JS const & src) {
	if (this == &src)
		return (*this);
	return (*this);
}

/*
	pub fn next(self: *Self) usize {
        self.latest_p2 <<= 1;
        self.latest_value = self.latest_p2 - self.latest_value;
        return self.latest_value;
    }
*/

unsigned int JS::next(void) {
	_latest_p2 *= 2;
	_latest_value = _latest_p2 - _latest_value;
	return (_latest_value);
}
