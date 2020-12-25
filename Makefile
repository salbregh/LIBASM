# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: salbregh <salbregh@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/22 14:35:59 by salbregh      #+#    #+#                  #
#    Updated: 2020/12/24 13:21:12 by salbregh      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a

SRC		=	ft_strlen.s \
			ft_strcmp.s \
			ft_strcpy.s \
			ft_strdup.s \
			ft_write.s \
			ft_read.s

OBJ		=	$(SRC:.s=.o)

NASM	=	nasm -f macho64

FLAGS	=	-Wall -Wextra -Werror

all:		$(NAME) test

$(NAME):	$(OBJ)
			ar rc $@ $^
			ranlib $@

%.o:		%.s
			$(NASM) $<
			
test:		$(NAME) $(OBJ) main.c
			gcc $(FLAGS) -L. -lasm main.c -o test

clean:
			/bin/rm -f $(OBJ)

fclean:		clean
			@/bin/rm -f $(NAME)
			@/bin/rm -f test

re: 		fclean all

.PHONY:		all test clean fclean re