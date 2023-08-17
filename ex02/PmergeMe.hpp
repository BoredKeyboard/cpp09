/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 15:16:34 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/17 14:37:42 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "Slice.hpp"
# include "JacobSequence.hpp"

# include <algorithm>

template<typename T>
class PmergeMe {
	private:
		Slice<T>		_nums;
		PmergeMe<T>*	_parent;
		unsigned int	_pair_count;
		bool	_has_uneven;
		int		_pair_gap;
		void	recurse(void);
		void	swapped(int index1, int index2);
		void	swap(int index1, int index2);
		void	sort_pairs(void);
		void	sort_pair(int pair_index);
		void	insertion(void);
		void	move(size_t from_index, size_t to_index);
		void	moved(size_t from_index, size_t to_index);
		size_t	binary_search(size_t from_index, size_t range, size_t value);

	public:
		PmergeMe(void);
		PmergeMe(T &nums);
		PmergeMe(T &nums, PmergeMe<T>* parent);
		PmergeMe(Slice<T> nums, PmergeMe<T>* parent);
		PmergeMe(PmergeMe<T> const & src);
		virtual ~PmergeMe(void);
		PmergeMe<T> & operator=(PmergeMe<T> const & src);
		void	sort(void);
};

# include "PmergeMe.tpp"

#endif
