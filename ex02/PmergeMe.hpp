/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/29 12:00:32 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/01 15:42:06 by mforstho      ########   odam.nl         */
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

	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const & src);
		virtual ~PmergeMe(void);
		PmergeMe & operator=(PmergeMe const & src);
};

#endif
