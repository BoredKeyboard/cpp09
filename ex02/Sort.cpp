/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sort.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 15:16:31 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/09 15:30:45 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Sort.hpp"

Sort::Sort(void) {
}

Sort::Sort(std::vector<int> nums, int num_count, Sort* parent) {
	_nums = nums;
	_has_uneven = num_count % 2;
	_parent = parent;
}

Sort::Sort(Sort const & src) {
}

Sort::~Sort(void) {
}

Sort & Sort::operator=(Sort const & src) {
	if (this == &src)
		return (*this);
	return (*this);
}
