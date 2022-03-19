# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: annaheister <annaheister@student.codam.nl>   +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/01 08:17:47 by annaheister   #+#    #+#                  #
#    Updated: 2022/03/01 08:17:47 by annaheister   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	bureaucrat

CFLAGS			=	-Wall -Werror -Wextra -std=c++98
CC				=	clang++

OBJ_FILES		=	Bureaucrat.o\
					Form.o\
					main.o\

HEADER_FILES	=   Bureaucrat.hpp\
					Form.hpp\

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
