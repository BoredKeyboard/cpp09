/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 15:16:31 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/16 15:35:18 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
}

PmergeMe::PmergeMe(std::vector<int> &nums) {
	_nums = VectorSlice(nums);
	_parent = NULL;
	_pair_count = nums.size() / 2;
	_has_uneven = nums.size() % 2;
	_pair_gap = _pair_count + _has_uneven;
}

PmergeMe::PmergeMe(VectorSlice nums, PmergeMe* parent) {
	_nums = nums;
	_parent = parent;
	_pair_count = nums.size() / 2;
	_has_uneven = nums.size() % 2;
	_pair_gap = _pair_count + _has_uneven;
}

PmergeMe::PmergeMe(PmergeMe const & src) {
}

PmergeMe::~PmergeMe(void) {
}

PmergeMe & PmergeMe::operator=(PmergeMe const & src) {
	if (this == &src)
		return (*this);
	return (*this);
}

void	PmergeMe::recurse(void) {
	// VectorSlice	slice(_nums.slice(_pair_gap));
	PmergeMe	subset(_nums.slice(_pair_gap), _parent);
	subset._parent = this;
	subset.sort();
}

void	PmergeMe::sort(void) {
	if (_pair_count == 0) {
		return ;
	}
	this->sort_pairs();
	this->recurse();
	this->insertion();
}

void	PmergeMe::swapped(int index1, int index2) {
	if (_parent) {
		_parent->swapped(index1 + _pair_gap, index2 + _pair_gap);
	}
	this->swap(index1, index2);
}

void	PmergeMe::swap(int index1, int index2) {
	if (index1 == index2) {
		return ;
	}
	int tmp = _nums[index1];
	_nums[index1] = _nums[index2];
	_nums[index2] = tmp;
	if (_parent) {
		_parent->swapped(index1, index2);
	}
}

void	PmergeMe::sort_pair(int pair_index) {
	if (_nums[pair_index] > _nums[pair_index + _pair_gap]) {
		this->swap(pair_index, pair_index + _pair_gap);
	}
}

void	PmergeMe::sort_pairs(void) {
	size_t	pair_index = 0;
	while (pair_index < _pair_count) {
		this->sort_pair(pair_index);
		pair_index++;
	}
}

void	PmergeMe::insertion(void) {
	size_t	to_sort = _pair_gap;
	this->move(0, _pair_gap - 1);
	to_sort--;

	JacobSequence js;
	while (to_sort > 0) {
		size_t	group_size = std::min(js.next(), to_sort);
		const int search_range = js._latest_p2 * 2 - 1;
		while (group_size > 0) {
			const size_t insertion_index = this->binary_search(to_sort, search_range, _nums[group_size - 1]);
			this->move(group_size - 1, insertion_index - 1);
			to_sort--;
			group_size--;
		}
	}
}

void	PmergeMe::move(size_t from_index, size_t to_index) {
	if (from_index == to_index) {
		return ;
	}
	_nums.move(from_index, to_index);
	if (_parent) {
		_parent->moved(from_index, to_index);
	}
}

void	PmergeMe::moved(size_t from_index, size_t to_index) {
	if (_parent) {
		_parent->moved(from_index + _pair_gap, to_index + _pair_gap);
	}
	this->move(from_index, to_index);
}

size_t	PmergeMe::binary_search(size_t from_index, size_t range, size_t value) {
	size_t	start = from_index;
	size_t	end = std::min(_nums.size(), from_index + range);
	while (start != end) {
		const size_t index = (start + end) / 2;
		const int i_value = _nums[index];
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

0 1 2 3 4 5
^

5

0 1 2 3 4 5

*/
