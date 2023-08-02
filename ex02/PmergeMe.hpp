/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/29 12:00:32 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/02 15:37:03 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <vector>

class PmergeMe {
	private:
		int			_left;
		int			_right;
		PmergeMe*	_parent;
	public:
		PmergeMe(void);
		PmergeMe(const int left, const int right, PmergeMe* parent);
		PmergeMe(PmergeMe const & src);
		virtual ~PmergeMe(void);
		PmergeMe & operator=(PmergeMe const & src);
		void	set_data(const int left, const int right, PmergeMe* parent);
};

#endif
