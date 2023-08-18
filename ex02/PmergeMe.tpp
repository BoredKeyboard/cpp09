/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.tpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/17 12:15:02 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/18 16:27:05 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename T>
PmergeMe<T>::PmergeMe(void) {
	_nums = NULL;
	_parent = NULL;
	_pair_count = 0;
	_has_uneven = 0;
	_pair_gap = 0;
}

template<typename T>
PmergeMe<T>::PmergeMe(T &nums) {
	_nums = Slice<T>(nums);
	_parent = NULL;
	_pair_count = nums.size() / 2;
	_has_uneven = nums.size() % 2;
	_pair_gap = _pair_count + _has_uneven;
}

template<typename T>
PmergeMe<T>::PmergeMe(Slice<T> nums, PmergeMe* parent) {
	_nums = nums;
	_parent = parent;
	_pair_count = nums.size() / 2;
	_has_uneven = nums.size() % 2;
	_pair_gap = _pair_count + _has_uneven;
}

template<typename T>
PmergeMe<T>::PmergeMe(PmergeMe const & src) {
	*this = src;
}

template<typename T>
PmergeMe<T>::~PmergeMe(void) {
}

template<typename T>
PmergeMe<T> & PmergeMe<T>::operator=(PmergeMe<T> const & src) {
	if (this == &src)
		return (*this);
	_nums = src._nums;
	_parent = src._parent;
	_pair_count = src._pair_count;
	_has_uneven = src._has_uneven;
	_pair_gap = src._pair_gap;
	return (*this);
}

template<typename T>
void	PmergeMe<T>::recurse(void) {
	PmergeMe<T>	subset(_nums.slice(_pair_gap), _parent);
	subset._parent = this;
	subset.sort();
}

template<typename T>
void	PmergeMe<T>::sort(void) {
	if (_pair_count == 0) {
		return ;
	}
	this->sort_pairs();
	this->recurse();
	this->insertion();
}

template<typename T>
void	PmergeMe<T>::swapped(int index1, int index2) {
	if (_parent) {
		_parent->swapped(index1 + _pair_gap, index2 + _pair_gap);
	}
	this->swap(index1, index2);
}

template<typename T>
void	PmergeMe<T>::swap(int index1, int index2) {
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

template<typename T>
void	PmergeMe<T>::sort_pair(int pair_index) {
	if (_nums[pair_index] > _nums[pair_index + _pair_gap]) {
		this->swap(pair_index, pair_index + _pair_gap);
	}
}

template<typename T>
void	PmergeMe<T>::sort_pairs(void) {
	size_t	pair_index = 0;
	while (pair_index < _pair_count) {
		this->sort_pair(pair_index);
		pair_index++;
	}
}

template<typename T>
void	PmergeMe<T>::insertion(void) {
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

template<typename T>
void	PmergeMe<T>::move(size_t from_index, size_t to_index) {
	if (from_index == to_index) {
		return ;
	}
	_nums.move(from_index, to_index);
	if (_parent) {
		_parent->moved(from_index, to_index);
	}
}

template<typename T>
void	PmergeMe<T>::moved(size_t from_index, size_t to_index) {
	if (_parent) {
		_parent->moved(from_index + _pair_gap, to_index + _pair_gap);
	}
	this->move(from_index, to_index);
}

template<typename T>
size_t	PmergeMe<T>::binary_search(size_t from_index, size_t range, size_t value) {
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
