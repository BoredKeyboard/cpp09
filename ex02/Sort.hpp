/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sort.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 15:16:34 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/09 15:30:54 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SORT_HPP
# define SORT_HPP

# include "PmergeMe.hpp"

class Sort {
	private:
		std::vector<int>	_nums;
		Sort*	_parent;
		uint	_pair_count;
		bool	_has_uneven;
	public:
		Sort(void);
		Sort(std::vector<int> nums, int num_count, Sort* parent);
		Sort(Sort const & src);
		virtual ~Sort(void);
		Sort & operator=(Sort const & src);
};

#endif
