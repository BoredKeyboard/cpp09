/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 15:16:34 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/16 15:36:28 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SORT_HPP
# define SORT_HPP

# include "PmergeMe.hpp"
# include "VectorSlice.hpp"
# include "JacobSequence.hpp"
# include <algorithm>
# include <vector>

class PmergeMe {
	private:
		VectorSlice	_nums;
		PmergeMe*	_parent;
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
		PmergeMe(std::vector<int> &nums);
		PmergeMe(std::vector<int> &nums, PmergeMe* parent);
		PmergeMe(VectorSlice nums, PmergeMe* parent);
		PmergeMe(PmergeMe const & src);
		virtual ~PmergeMe(void);
		PmergeMe & operator=(PmergeMe const & src);

		void	sort(void);
};

#endif
