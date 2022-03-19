# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: annaheister <annaheister@student.codam.nl>   +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/21 09:18:49 by annaheister   #+#    #+#                  #
#    Updated: 2022/02/21 09:18:49 by annaheister   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	animals

CFLAGS			=	-Wall -Werror -Wextra -std=c++98
CC				=	clang++

OBJ_FILES		=	Animal.o\
					WrongAnimal.o\
					Cat.o\
					WrongCat.o\
					Dog.o\
                	main.o\

HEADER_FILES	=   Animal.hpp\
					WrongAnimal.hpp\
					Cat.hpp\
					WrongCat.hpp\
					Dog.hpp\

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
