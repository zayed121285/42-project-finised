# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 08:48:51 by zsid-ele          #+#    #+#              #
#    Updated: 2025/03/14 10:56:14 by zsid-ele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/push_moves.c	src/quicksort.c	src/rev_rot_moves.c	src/rotation_moves.c	src/sortage.c	src/swap_moves.c src/utils.c push_swap.c

CFLAGS = -Wall -Werror -Wextra

CC = cc

rm = rm -f

libft.d = libft/

printf.d = ft_printf/

printf = $(addprefix ${printf.d}, libftprintf.a)

libft = $(addprefix ${libft.d}, libft.a)

NAME = push_swap

all: $(NAME)

$(NAME): 	$(OBJ) $(libft) $(printf)
			@$(CC) $(CFLAGS) $(SRC) $(libft) $(printf) -o ${NAME}
			@echo "File is READY NAME of file: \033[0;32mpush_swap\033[0m"

$(libft): 
			@$(MAKE) -s -C $(libft.d)
$(printf):
			@$(MAKE) -s -C $(printf.d)
.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
				@echo "Compiling $<."

cleandir:
		@cd libft && make -s fclean
		@cd ft_printf && make -s fclean

clean:	cleandir

fclean: clean 
		@$(rm) $(NAME)

re: fclean all

.PHONY: all clean fclean re cleandir .c.o 
