/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sort.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 15:16:31 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/12 14:09:21 by mforstho      ########   odam.nl         */
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

// Sort	Sort::sort_internal(Sort &slice) {
// 	Sort	new_slice();
// }

void	Sort::recurse(void) {
	VectorSlice	slice(this->_nums.slice(this->_pair_gap));
	Sort	subset(_nums.slice(this->_pair_gap), );
}

void	Sort::sort_internal(void) {
	if (this->_pair_count == 0) {
		return ;
	}
	this->sort_pairs();
	this->recurse();
}

void	Sort::swapped(int index1, int index2) {
	if (this->_parent) {
		_parent->swapped(index1 + this->_pair_gap, index2 + this->_pair_gap);
	}
	this->swap(index1, index2);
}

void	Sort::swap(int index1, int index2) {
	if (index1 == index2) {
		return ;
	}
	int tmp = this->_nums[index1];
	this->_nums[index1] = this->_nums[index2];
	this->_nums[index2] = tmp;
	if (this->_parent) {
		_parent->swapped(index1, index2);
	}
}

void	Sort::sort_pair(int pair_index) {
	if (this->_nums[pair_index] > this->_nums[pair_index + this->_pair_gap]) {

	}
}

void	Sort::sort_pairs(void) {
	int	pair_index = 0;
	while (pair_index < this->_pair_count) {
		this->sort_pair(pair_index);
		pair_index++;
	}
}
