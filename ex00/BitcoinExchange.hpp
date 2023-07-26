/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 16:00:53 by mforstho      #+#    #+#                 */
/*   Updated: 2023/07/26 16:15:20 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>

# define MIN_YEAR 2000
# define MAX_YEAR 2023

class BitcoinExchange {
	private:
		std::map<std::string, float>	_datamap;
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & src);
		virtual ~BitcoinExchange(void);
		BitcoinExchange & operator=(BitcoinExchange const & src);

	public:
		static bool is_valid_date(int y, int m, int d);
};

#endif
