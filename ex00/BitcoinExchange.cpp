/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 16:00:56 by mforstho      #+#    #+#                 */
/*   Updated: 2023/07/26 16:26:30 by mforstho      ########   odam.nl         */
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

std::map<std::string, float>	BitcoinExchange::save_data(std::string data) {
	std::map<std::string, float> datamap;
	std::ifstream	inputdata(data);
	std::string	line;

	getline(inputdata, line);
	while (getline(inputdata, line)) {
		std::string	date = line.substr(0, line.find(","));
		float	value = atof((line.substr(line.find(",") + 1, line.find("\n"))).c_str());
		datamap.insert(std::pair<std::string,float>(date, value));
	}
	return (datamap);
}

void	BitcoinExchange::find_data(std::string file, std::map<std::string, float> datamap) {
	std::ifstream inputfile(file);
	std::string	line;
	getline(inputfile, line);
	while (getline(inputfile, line)) {
		if (!is_valid_date(atoi((line.substr(0, 4)).c_str()), atoi((line.substr(5, 2)).c_str()), atoi((line.substr(8, 2)).c_str()))) {
			std::cout << "Error: bad input => " << line << std::endl;
		}
		else if (line.find(" | ") == line.npos) {
			std::cout << "Error: wrong format => " << line << std::endl;
		}
		else {
			std::string	date = line.substr(0, line.find(" | "));
			std::string	value = line.substr(line.find(" | ") + 3, line.find("\n"));
			if (value.c_str()[0] == '-') {
				std::cout << "Error: not a positive number." << std::endl;
			}
			else if ((unsigned int)std::atoi(value.c_str()) > 1000){
				std::cout << "Error: too large a number." << std::endl;
			}
			else {
				std::map<std::string,float>::iterator it;
				it = --datamap.upper_bound(date);
				// std::cout << "Date: " << date << "    Value: " << value << std::endl;
				// std::cout << "Date: " << it->first << "    Value: " << it->second << std::endl;
				std::cout << date << " => " << value << " = " << (it->second * atof(value.c_str())) << std::endl;
			}
		}
		// std::cout << std::endl;
	}
}
