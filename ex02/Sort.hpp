/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sort.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 15:16:34 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/10 16:07:37 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SORT_HPP
# define SORT_HPP

# include "PmergeMe.hpp"
# include "VectorSlice.hpp"

class Sort {
	private:
		VectorSlice	_nums;
		Sort*	_parent;
		uint	_pair_count;
		bool	_has_uneven;
		int		_pair_gap;
	public:
		Sort(void);
		Sort(std::vector<int> &nums, int num_count, Sort* parent);
		Sort(VectorSlice nums, int num_count, Sort* parent);
		Sort(Sort const & src);
		virtual ~Sort(void);
		Sort & operator=(Sort const & src);

		void	recurse(void);
		void	sort_internal(void);
		void	swapped(int index1, int index2);
		void	swap(int index1, int index2);
		void	sort_pairs(void);
		void	sort_pair(int pair_index);
};

#endif
