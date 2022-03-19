# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: annaheister <annaheister@student.codam.nl>   +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/16 13:39:49 by annaheister   #+#    #+#                  #
#    Updated: 2022/02/16 13:39:49 by annaheister   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	fragtrap

CFLAGS			=	-Wall -Werror -Wextra -std=c++98
CC				=	clang++

OBJ_FILES		=	ClapTrap.o\
					ScavTrap.o\
					FragTrap.o\
                	main.o\

HEADER_FILES	=   ClapTrap.hpp\
					ScavTrap.hpp\
					FragTrap.hpp\

%.o:				%.cpp $(HEADER_FILES)
					$(CC) -c $(CFLAGS) -o $@ $<

all:				$(NAME)

$(NAME):			$(OBJ_FILES)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

clean:
					rm -f $(OBJ_FILES)

fclean: 			clean
					rm -f $(NAME)

re:
					$(MAKE) fclean
					$(MAKE) all

.PHONY:				all clean fclean re
