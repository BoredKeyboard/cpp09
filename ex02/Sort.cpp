/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sort.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 15:16:31 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/15 16:24:51 by mforstho      ########   odam.nl         */
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

void	Sort::recurse(void) {
	// VectorSlice	slice(this->_nums.slice(this->_pair_gap));
	Sort	subset(this->_nums.slice(this->_pair_gap), this->_nums.size(), this->_parent);
	subset._parent = this;
	subset.sort_internal();
}

void	Sort::sort_internal(void) {
	if (this->_pair_count == 0) {
		return ;
	}
	this->sort_pairs();
	this->recurse();
	this->insertion();
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

void	Sort::insertion(void) {
	size_t	to_sort = _pair_gap;
	this->move(0, _pair_gap - 1);
	to_sort--;

	JS js;
	while (to_sort > 0) {
		size_t	group_size = std::min(js.next(), to_sort);
		const int search_range = js._latest_p2 * 2 - 1;
		while (group_size > 0) {
			const int insertion_index = this->binary_search(to_sort, search_range, _nums[group_size - 1]);
			this->move(group_size - 1, insertion_index - 1);
			to_sort--;
			group_size--;
		}
	}
}

void	Sort::move(size_t from_index, size_t to_index) {
	if (from_index == to_index) {
		return ;
	}
	if (from_index < to_index) {
		VectorSlice tmp = _nums.slice(from_index);
		// copyForwards
		_nums[to_index] = tmp; // klopt nog niet
		if (_parent) {
			_parent->moved(from_index, to_index);
		}
	}
	else {
		VectorSlice tmp = _nums.slice(from_index);
		// copyBackwords
		_nums[to_index] = tmp; // klopt nog niet
		if (_parent) {
			_parent->moved(from_index, to_index);
		}
	}
}

void	Sort::moved(size_t from_index, size_t to_index) {
	if (_parent) {
		_parent->moved(from_index + _pair_gap, to_index + _pair_gap);
	}
	this->move(from_index, to_index);
}

size_t	Sort::binary_search(size_t from_index, size_t range, size_t value) {
	size_t	start = from_index;
	size_t	end = std::min(_nums.size(), from_index + range);
	while (start != end) {
		const size_t index = (start + end) / 2;
		const size_t i_value = _nums[index];
		if (value == i_value) {
			return (index);
		}
		else if (value < i_value) {
			end = index;
		}
		else {
			start = index + 1;
		}
	}
	return (start);
}

/*

*/
