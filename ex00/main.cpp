/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 16:00:10 by mforstho      #+#    #+#                 */
/*   Updated: 2023/07/27 13:31:38 by mforstho      ########   odam.nl         */
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
	datamap = BitcoinExchange::save_data("data.csv");

			// to display the saved map
	// std::map<std::string,float>::iterator it=datamap.begin();
	// for (int i = 0; i < 3000; i++) {
   	// 	std::cout << it->first << " => " << it->second << std::endl;
	// 	it++;
	// 	if (it == datamap.end())
	// 		break ;
	// }
	return (BitcoinExchange::find_data(argv[1], datamap));
}
