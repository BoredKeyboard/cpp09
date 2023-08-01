# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mforstho <mforstho@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/31 11:22:02 by mforstho      #+#    #+#                  #
#    Updated: 2023/07/29 11:59:53 by mforstho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := PmergeMe
CC := c++
CFLAGS ?= -Wextra -Wall -Werror -std=c++98 -pedantic #-fsanitize=address -g

SOURCES := $(wildcard *.cpp)

HEADERS := $(wildcard *.hpp)
OBJDIR := obj
OBJECTS := $(addprefix $(OBJDIR)/, $(SOURCES:cpp=o))


INCLUDES := $(addprefix -I, $(sort $(dir $(HEADERS))))
CFLAGS += $(INCLUDES) -DPROGRAM_NAME=\"$(NAME)\"

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(OBJDIR)/%.o : %.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
