/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/29 12:00:04 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/01 15:42:37 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	fill_vector(int argc, char *argv[]) {
	std::vector<int>	unsorted;
	for (int i = 1; i < argc; i++) {
		unsorted.push_back(atoi(argv[i]));
	}
	for (int i = 0; i + 1< argc; i++) {
		std::cout << unsorted.at(i) << std::endl;
	}
	return (unsorted);
}

int	main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Error: need input" << std::endl;
		return (EXIT_FAILURE);
	}


	std::vector<int>	unsorted;
	unsorted = fill_vector(argc, argv);

	return (EXIT_SUCCESS);
}
