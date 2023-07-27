/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 16:00:53 by mforstho      #+#    #+#                 */
/*   Updated: 2023/07/27 13:21:00 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <cctype>

# define MIN_YEAR 2000
# define MAX_YEAR 2023

class BitcoinExchange {
	private:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & src);
		virtual ~BitcoinExchange(void);
		BitcoinExchange & operator=(BitcoinExchange const & src);

	public:
		static bool is_valid_date(int y, int m, int d);
		static std::map<std::string, float>	save_data(std::string data);
		static bool	is_valid_input(std::string input);
		static int	find_data(std::string file, std::map<std::string, float> datamap);
};

#endif
