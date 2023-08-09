/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   VectorSlice.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 16:29:54 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/09 16:42:40 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef VECTORSLICE_HPP
# define VECTORSLICE_HPP

# include <vector>

struct VectorSlice {
	std::vector<int> *nums;
	size_t start;
	size_t end;

	VectorSlice(void);
	VectorSlice(std::vector<int> &nums);
	VectorSlice(std::vector<int> &nums, size_t start);
	VectorSlice(std::vector<int> &nums, size_t start, size_t end);

	int &operator[](size_t index);
	VectorSlice slice(size_t start, size_t end) const;
	VectorSlice slice(size_t start) const;
	size_t	size(void) const;
};

#endif
