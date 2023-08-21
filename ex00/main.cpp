/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 16:00:10 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/21 14:37:16 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iomanip>

int	main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Error: could not open file" << std::endl;
		return (EXIT_FAILURE);
	}
	else if (argc > 2) {
		std::cout << "Error: too many arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	std::map<std::string, float>	datamap;

	std::ifstream	inputdata("data.csv");
	if (!inputdata.is_open()) {
		std::cout << "Error: \'data.csv\' not found" << std::endl;
		return (EXIT_FAILURE);
	}
	datamap = BitcoinExchange::save_data("data.csv");
	return (BitcoinExchange::find_data(argv[1], datamap));
}
