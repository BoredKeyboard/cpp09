/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 13:51:11 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/18 14:46:11 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	RPN::is_operator(int c) {
	if (c == '+') {
		return (ADD);
	}
	if (c == '-') {
		return (SUBTRACT);
	}
	if (c == '*') {
		return (MULTIPLY);
	}
	if (c == '/') {
		return (DIVIDE);
	}
	return (NO_OPERATOR);
}

bool	RPN::is_valid_input(std::string input) {
	for (int i = 0; input[i] != '\0'; i++) {
		if (isdigit(input[i]) == 0 && !(input[i] == '+' || input[i] == '-'
			|| input[i] == '*' || input[i] == '/' || input[i] == ' ')) {
			std::cout << "Error: invalid character in input: " << input[i] << std::endl;
			return (false);
		}
	}
	return (true);
}

int	RPN::do_rpn(std::string input) {
	std::stack<int>	numbers;
	int	left;
	int	right;

	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] != ' ') {
			if (input[i + 1] != ' ' && input[i + 1] != '\0') {
				std::cout << "Error: missing spaces between digits/operators" << std::endl;
				return (EXIT_FAILURE);
			}
			if (is_operator(input[i]) == 0) {
				numbers.push(input[i] - '0');
			}
			else {
				if (numbers.size() < 2) {
					std::cout << "Error: too many operators" << std::endl;
					return (EXIT_FAILURE);
				}
				right = numbers.top();
				numbers.pop();
				left = numbers.top();
				numbers.pop();
				switch (is_operator(input[i])) {
					case (ADD) : {
						numbers.push(left + right);
						break ;
					}
					case (SUBTRACT) : {
						numbers.push(left - right);
						break ;
					}
					case (MULTIPLY) : {
						numbers.push(left * right);
						break ;
					}
					case (DIVIDE) : {
						if (right == 0) {
							std::cout << "Error: division by zero (0) is not allowed" << std::endl;
							return (EXIT_FAILURE);
						}
						numbers.push(left / right);
						break ;
					}
				}
			}
		}
	}
	if (numbers.size() != 1) {
		std::cout << "Error: too many numbers without operators" << std::endl;
		return (EXIT_FAILURE);
	}
	std::cout << numbers.top() << std::endl;
	return (EXIT_SUCCESS);
}
