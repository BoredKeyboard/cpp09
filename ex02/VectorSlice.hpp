/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   VectorSlice.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 16:29:54 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/16 15:25:53 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef VECTORSLICE_HPP
# define VECTORSLICE_HPP

# include <vector>

class VectorSlice {	// ocf maken
	private:
		std::vector<int> *_nums;
		size_t _start;
		size_t _end;

	public:
		VectorSlice(void);
		VectorSlice(std::vector<int> &nums);
		VectorSlice(std::vector<int> &nums, size_t start);
		VectorSlice(std::vector<int> &nums, size_t start, size_t end);

		int &operator[](size_t index);
		VectorSlice slice(size_t start, size_t end) const;
		VectorSlice slice(size_t start) const;
		size_t	size(void) const;
		void	erase(size_t from_index);
		void	insert(size_t to_index, int value);
		void	move(size_t from_index, size_t to_index);
};

#endif
