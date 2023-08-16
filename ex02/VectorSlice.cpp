/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   VectorSlice.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 16:30:50 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/16 15:33:12 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "VectorSlice.hpp"

VectorSlice::VectorSlice() : _nums(nullptr), _start(0), _end(0) {}
VectorSlice::VectorSlice(std::vector<int> &nums) : _nums(&nums), _start(0), _end(nums.size()) {}
VectorSlice::VectorSlice(std::vector<int> &nums, size_t start) : _nums(&nums), _start(start), _end(nums.size()) {}
VectorSlice::VectorSlice(std::vector<int> &nums, size_t start, size_t end) : _nums(&nums), _start(start), _end(end) {}

int &VectorSlice::operator[](size_t index) {
	// if (index > end - start)
	// 	throw std::exception("no");
	return ((*_nums)[index + _start]);
}

VectorSlice VectorSlice::slice(size_t start, size_t end) const {
	return (VectorSlice(*_nums, _start + start, _start + end));
}

VectorSlice VectorSlice::slice(size_t start) const {
	return (VectorSlice(*_nums, _start + start, _end));
}

size_t VectorSlice::size() const {
	return (_end - _start);
}

void	VectorSlice::erase(size_t from_index) {
	_nums->erase(_nums->begin() + _start + from_index);
}

void	VectorSlice::insert(size_t to_index, int value) {
	_nums->insert(_nums->begin() + _start + to_index, value);
}

void	VectorSlice::move(size_t from_index, size_t to_index) {
	if (from_index == to_index) {
		return ;
	}
	int tmp = (*this)[from_index];
	if (from_index < to_index) {
		this->erase(from_index);
		this->insert(to_index, tmp);
	}
	else {
		this->erase(from_index);
		this->insert(to_index + 1, tmp);
	}
}

/*

*/
