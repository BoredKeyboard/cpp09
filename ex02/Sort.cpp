/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sort.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 15:16:31 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/09 16:29:46 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Sort.hpp"

Sort::Sort(void) {
}

Sort::Sort(std::vector<int> &nums, int num_count, Sort* parent) : Sort(VectorSlice(nums), num_count, parent) {}

Sort::Sort(VectorSlice nums, int num_count, Sort* parent) {
	_nums = nums;
	_parent = parent;
	_pair_count = num_count / 2;
	_has_uneven = num_count % 2;
	_pair_gap = _pair_count + _has_uneven;
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
