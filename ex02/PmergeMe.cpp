/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/29 12:01:32 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/03 13:14:26 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
	_parent_left = NULL;
	_parent_right = NULL;
}

PmergeMe::PmergeMe(const int left, const int right, PmergeMe* parent_left, PmergeMe* parent_right) {
	_left = left;
	_right = right;
	_parent_left = parent_left;
	_parent_right = parent_right;
}

PmergeMe::PmergeMe(PmergeMe const & src) {
	_left = src._left;
	_right = src._right;
	_parent_left = src._parent_left;
	_parent_right = src._parent_right;
}

PmergeMe::~PmergeMe(void) {
}

PmergeMe & PmergeMe::operator=(PmergeMe const & src) {
	if (this == &src)
		return (*this);
	_left = src._left;
	_right = src._right;
	_parent_left = src._parent_left;
	_parent_right = src._parent_right;
	return (*this);
}

void	PmergeMe::set_data(const int left, const int right, PmergeMe* parent_left, PmergeMe* parent_right) {
	_left = left;
	_right = right;
	_parent_left = parent_left;
	_parent_right = parent_right;
}

int	PmergeMe::get_left(void) {
	return (_left);
}

int	PmergeMe::get_right(void) {
	return (_right);
}

PmergeMe*	PmergeMe::get_parent_left(void) {
	return (_parent_left);
}

PmergeMe*	PmergeMe::get_parent_right(void) {
	return (_parent_right);
}
