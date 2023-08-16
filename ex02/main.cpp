/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 15:11:49 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/16 16:20:41 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PmergeMe.hpp"
#include "VectorSlice.hpp"
#include "JacobSequence.hpp"

std::vector<int>	fill_vector(int argc, char *argv[]) {
	std::vector<int>	unsorted;
	for (int i = 1; i < argc; i++) {
		unsorted.push_back(atoi(argv[i]));
	}
	return (unsorted);
}

void	print_vector(std::string prefix, std::vector<int> nums) {
	std::cout << prefix;
	for (int i = 0; i < nums.size(); i++) {
		std::cout << " " << nums.at(i);
	}
	std::cout << std::endl;
}

int	main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Error: need input" << std::endl;
		return (EXIT_FAILURE);
	}

	std::vector<int> nums = fill_vector(argc, argv);
	print_vector("Before:", nums);
	PmergeMe s(nums);
	s.sort();
	print_vector("After:", nums);
	std::cout << "";


	// std::cout << std::endl << std::endl;
	// JS bruh;
	// for (int i = 0; i < 10; i++) {
	// 	std::cout << bruh.next() << std::endl;
	// }

	return (EXIT_SUCCESS);
}
