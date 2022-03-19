# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: annaheister <annaheister@student.codam.nl>   +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/01 17:00:34 by annaheister   #+#    #+#                  #
#    Updated: 2022/02/01 17:00:34 by annaheister   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	violence

CFLAGS			=	-Wall -Werror -Wextra -std=c++98
CC				=	clang++

OBJ_FILES		=	HumanA.o\
					HumanB.o\
					Weapon.o\
                	main.o\

HEADER_FILES	=   HumanA.hpp\
					HumanB.hpp\
					Weapon.hpp\

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