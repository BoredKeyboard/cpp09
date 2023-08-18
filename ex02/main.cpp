/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 15:11:49 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/18 14:47:39 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

#include "PmergeMe.hpp"
#include "Slice.hpp"
#include "JacobSequence.hpp"

std::vector<int>	create_vector(int argc, char *argv[]) {
	std::vector<int>	unsorted;
	for (int i = 1; i < argc; i++) {
		unsorted.push_back(atoi(argv[i]));
	}
	return (unsorted);
}

std::list<int>		create_list(int argc, char *argv[]) {
	std::list<int>	unsorted;
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

	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

	std::vector<int> nums = create_vector(argc, argv);
	PmergeMe< std::vector<int> > s(nums);
	s.sort();

	std::chrono::time_point<std::chrono::high_resolution_clock> mid = std::chrono::high_resolution_clock::now();

	std::list<int> list_nums = create_list(argc, argv);
	PmergeMe< std::list<int> > s2(list_nums);
	s2.sort();

	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

	std::cout << "Before:";
	for (size_t i = 1; i < argc; i++) {
		std::cout << " " << argv[i];
	}
	std::cout << std::endl;
	print_vector("After: ", nums);
	std::chrono::duration<double> diff1 = mid - start;
	std::chrono::duration<double> diff2 = end - mid;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << diff1.count() * 1000 * 1000 << " μs" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::list   : " << diff2.count() * 1000 * 1000 << " μs" << std::endl;

	for (size_t i = 1; i < nums.size(); i++) {
		assert(nums[i - 1] <= nums[i]);
	}
	return (EXIT_SUCCESS);
}
