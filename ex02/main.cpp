/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/29 12:00:04 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/02 16:08:31 by mforstho      ########   odam.nl         */
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

PmergeMe**	make_first_pairs(std::vector<int> unsorted, int argc) {
	PmergeMe**	set = NULL;
	for (int i = 0; i < argc; i+=2) {
		if (unsorted.at(i) < unsorted.at(i + 1)) {
			set[i] = new PmergeMe(unsorted.at(i), unsorted.at(i + 1), NULL);
		}
		else {
			set[i] = new PmergeMe(unsorted.at(i + 1), unsorted.at(i), NULL);
		}
	}
	return (set);
}

void	make_pairs_sort(PmergeMe** set, int set_count) {
	PmergeMe**	new_set = NULL;
	for (int i = 0; i < set_count; i+=2) {
		new_set[i]
	}
}

int	main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Error: need input" << std::endl;
		return (EXIT_FAILURE);
	}

	std::vector<int>	unsorted;
	unsorted = fill_vector(argc, argv);
	PmergeMe**	set = make_first_pairs(unsorted, argc);

	return (EXIT_SUCCESS);
}
