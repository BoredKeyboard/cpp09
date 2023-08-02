/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/29 12:01:32 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/02 15:36:58 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
	_parent = NULL;
}

PmergeMe::PmergeMe(const int left, const int right, PmergeMe* parent) {
	_left = left;
	_right = right;
	_parent = parent;
}

PmergeMe::PmergeMe(PmergeMe const & src) {
	_left = src._left;
	_right = src._right;
	_parent = src._parent;
}

PmergeMe::~PmergeMe(void) {
}

PmergeMe & PmergeMe::operator=(PmergeMe const & src) {
	if (this == &src)
		return (*this);
	_left = src._left;
	_right = src._right;
	_parent = src._parent;
	return (*this);
}

void	PmergeMe::set_data(const int left, const int right, PmergeMe* parent) {
	_left = left;
	_right = right;
	_parent = parent;
}
