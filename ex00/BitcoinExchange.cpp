/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 16:00:56 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/21 14:35:25 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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

bool	BitcoinExchange::is_valid_input(std::string input) {
	if (input.find(" | ") != 10) {
		return (false);
	}
	for (int i = 0; i < 10; i++) {
		if ((i == 4 || i == 7) && input[i] != '-') {
			std::cout << input[i] << std::endl;
			return (false);
		}
		else if (input[i] != '-' && isdigit(input[i]) == 0) {
			return (false);
		}
	}
	int	i = input.find(" | ") + 3;
	while (input[i] != '\0') {
		if (input[i] != '.' && input[i] != '-' && std::isdigit(input[i]) == 0) {
			return (false);
		}
		i++;
	}
	return (true);
}

int	BitcoinExchange::find_data(std::string file, std::map<std::string, float> datamap) {
	std::ifstream inputfile(file);
	std::string	line;
	if (!inputfile.is_open()) {
		std::cout << "Error: file does not exist" << std::endl;
		return (EXIT_FAILURE);
	}
	getline(inputfile, line);
	if (line != "date | value") {
		std::cout << "Error: invalid first line" << std::endl;
		return (EXIT_FAILURE);
	}
	while (getline(inputfile, line)) {
		if (!is_valid_input(line)) {
			std::cout << "Error: bad input => " << line << std::endl;
		}
		else if (!is_valid_date(std::stoi(line.substr(0, 4)), stoi(line.substr(5, 2)), stoi(line.substr(8, 2)))) {
			std::cout << "Error: invalid date => " << line << std::endl;
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
				it = datamap.upper_bound(date);
				if (it != datamap.begin()) {
					it--;
				}
				std::cout << date << " => " << value << " = " << (it->second * atof(value.c_str())) << std::endl;
			}
		}
	}
	return (EXIT_SUCCESS);
}
