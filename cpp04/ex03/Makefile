# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: annaheister <annaheister@student.codam.nl>   +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/22 12:15:57 by annaheister   #+#    #+#                  #
#    Updated: 2022/02/22 12:15:57 by annaheister   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	materia

CFLAGS			=	-Wall -Werror -Wextra -std=c++98
CC				=	clang++

OBJ_FILES		=	AMateria.o\
					Character.o\
					Cure.o\
					Ice.o\
					MateriaSource.o\
                	main.o\

HEADER_FILES	=   AMateria.hpp\
					Character.hpp\
					Cure.hpp\
					Ice.hpp\
					ICharacter.hpp\
					IMateriaSource.hpp\
					MateriaSource.hpp\

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