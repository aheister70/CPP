# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aheister <aheister@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/30 20:50:09 by aheister      #+#    #+#                  #
#    Updated: 2021/10/30 21:07:02 by aheister      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	megaphone

CFLAGS		=	-Wall -Werror -Wextra -std=c++98
CC			=	clang++

OBJ_FILES	=	megaphone.o

%.o:			%.cpp
				$(CC) -c $(CFLAGS) -o $@ $<

all:			$(NAME)

$(NAME):		$(OBJ_FILES)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

clean:
				rm -f $(OBJ_FILES)

fclean: 		clean
				rm -f $(NAME)

re:
				$(MAKE) fclean
				$(MAKE) all

.PHONY:			all clean fclean re