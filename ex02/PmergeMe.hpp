/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/29 12:00:32 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/03 13:14:44 by mforstho      ########   odam.nl         */
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
		PmergeMe*	_parent_left;
		PmergeMe*	_parent_right;
	public:
		PmergeMe(void);
		PmergeMe(const int left, const int right, PmergeMe* parent_left, PmergeMe* parent_right);
		PmergeMe(PmergeMe const & src);
		virtual ~PmergeMe(void);
		PmergeMe & operator=(PmergeMe const & src);
		void	set_data(const int left, const int right, PmergeMe* parent_left, PmergeMe* parent_right);
		int	get_left(void);
		int	get_right(void);
		PmergeMe*	get_parent_left(void);
		PmergeMe*	get_parent_right(void);
};

#endif
