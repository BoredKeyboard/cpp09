/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 13:51:16 by mforstho      #+#    #+#                 */
/*   Updated: 2023/07/27 15:49:32 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	is_operator(int c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return (true);
	}
	return (false);
}

int	main(int argc, char *argv[]) {
	if (argc < 1) {
		std::cout << "Error: need input" << std::endl;
		return (EXIT_FAILURE);
	}
	if (argc > 2) {
		std::cout << "Error: too many arguments" << std::endl;
		return (EXIT_FAILURE);
	}

	std::string		input(argv[1]);
	for (int i = 0; input[i] != '\0'; i++) {
		if (isdigit(input[i]) == 0 && !(input[i] == '+' || input[i] == '-'
			|| input[i] == '*' || input[i] == '/' || input[i] == ' ')) {
			std::cout << "Error: invalid character in input: " << input[i] << std::endl;
			return (EXIT_FAILURE);
		}
	}
	std::stack<int>	numbers;
	int	left;
	int	right;
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] != ' ') {
			if (!is_operator(input[i])) {
				numbers.push(input[i]);
			}
			else {
				
			}
		}
	}
	return (EXIT_SUCCESS);
}
