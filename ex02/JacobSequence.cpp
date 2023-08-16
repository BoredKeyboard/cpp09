/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   JacobSequence.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 16:33:26 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/16 15:36:43 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "JacobSequence.hpp"

JacobSequence::JacobSequence(void) : _latest_value(0), _latest_p2(1) {}

size_t JacobSequence::next(void) {
	_latest_p2 *= 2;
	_latest_value = _latest_p2 - _latest_value;
	return (_latest_value);
}
