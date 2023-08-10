/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   VectorSlice.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 16:30:50 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/10 14:24:17 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "VectorSlice.hpp"

VectorSlice::VectorSlice() : nums(nullptr), start(0), end(0) {}
VectorSlice::VectorSlice(std::vector<int> &nums) : nums(&nums), start(0), end(nums.size()) {}
VectorSlice::VectorSlice(std::vector<int> &nums, size_t start) : nums(&nums), start(start), end(nums.size()) {}
VectorSlice::VectorSlice(std::vector<int> &nums, size_t start, size_t end) : nums(&nums), start(start), end(end) {}

int &VectorSlice::operator[](size_t index) {
	// if (index > end - start)
	// 	throw std::exception("no");
	return ((*nums)[index + start]);
}

VectorSlice VectorSlice::slice(size_t start, size_t end) const {
	return (VectorSlice(*nums, this->start + start, this->start + end));
}

VectorSlice VectorSlice::slice(size_t start) const {
	return (VectorSlice(*nums, this->start + start, this->end));
}

size_t VectorSlice::size() const {
	return (end - start);
}
