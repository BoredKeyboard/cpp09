/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Slice.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 16:29:54 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/18 16:22:08 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SLICE_HPP
# define SLICE_HPP

# include <cstddef>

template <typename T>
class Slice {	// ocf maken
	private:
		T *_nums;
		size_t _start;
		size_t _end;

	public:
		Slice(void);
		Slice(T &nums);
		Slice(T &nums, size_t start);
		Slice(T &nums, size_t start, size_t end);
		Slice(Slice const & src);
		virtual ~Slice(void);
		Slice<T> & operator=(Slice<T> const & src);

		typename T::value_type &operator[](size_t index);
		Slice<T> slice(size_t start, size_t end) const;
		Slice<T> slice(size_t start) const;
		size_t	size(void) const;
		void	erase(size_t from_index);
		void	insert(size_t to_index, typename T::value_type value);
		void	move(size_t from_index, size_t to_index);
};

# include "Slice.tpp"

#endif
