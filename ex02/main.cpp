/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 15:11:49 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/12 14:09:19 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Sort.hpp"
#include "VectorSlice.hpp"
#include "JS.hpp"

std::vector<int>	fill_vector(int argc, char *argv[]) {
	std::vector<int>	unsorted;
	for (int i = 1; i < argc; i++) {
		unsorted.push_back(atoi(argv[i]));
	}
	for (int i = 0; i + 1< argc; i++) {	// only to print
		std::cout << unsorted.at(i) << std::endl;
	}
	return (unsorted);
}

/*

checken of er meer dan 1 paar over is
van i = pair gap iteraten tot tot het einde
bij elk getal kijken of ie groter is dan zn gepairde die links staat
in het geval het getal kleiner is dan zn gepairde getal moeten ze geswapt worden
checken of er een parent is en dit dan ook in de parent aanpassen

*/

int	main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Error: need input" << std::endl;
		return (EXIT_FAILURE);
	}

	std::vector<int> nums = fill_vector(argc, argv);
	VectorSlice	slice(nums);




	// std::cout << std::endl << std::endl;
	// JS bruh;
	// for (int i = 0; i < 10; i++) {
	// 	std::cout << bruh.next() << std::endl;
	// }

	return (EXIT_SUCCESS);
}
