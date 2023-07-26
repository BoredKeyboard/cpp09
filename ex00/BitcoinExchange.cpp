/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 16:00:56 by mforstho      #+#    #+#                 */
/*   Updated: 2023/07/26 16:16:03 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {
}

BitcoinExchange::~BitcoinExchange(void) {
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & src) {
	if (this == &src)
		return (*this);
	return (*this);
}

bool	BitcoinExchange::is_valid_date(int y, int m, int d) {
	if (y < MIN_YEAR || y > MAX_YEAR) {
		return (false);
	}
	if (m < 1 || m > 12) {
		return (false);
	}
	if (d < 1 || d > 31) {
		return (false);
	}
	if (m == 2) {
		return (d <= 28);
	}
	if (m == 4 || m == 6 || m == 9 || m == 11) {
		return (d <= 30);
	}
	return (true);
}

// void	BitcoinExchange::save_data() {
// 	std::string	line;

// 	getline(inputdata, line);
// 	while (getline(inputdata, line)) {
// 		std::string	date = line.substr(0, line.find(","));
// 		float	value = atof((line.substr(line.find(",") + 1, line.find("\n"))).c_str());
// 		datamap.insert(std::pair<std::string,float>(date, value));
// 	}
// }
