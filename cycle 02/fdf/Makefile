# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 10:37:51 by zsid-ele          #+#    #+#              #
#    Updated: 2025/02/17 18:47:29 by zsid-ele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
LIBFT		=	libft/
GNL			=	gnl/
MLX			=	src/mlx/
LIBFT_A		=	$(addprefix $(LIBFT), libft.a)
MLX_A		=	$(addprefix $(MLX), libmlx.a)

CC			=	cc

INCLUDE 	=	headers

CFLAGS		=	-Wall -Wextra -Werror -I$(INCLUDE)

RM			=	rm -f

SRCS		=	src/Brensham.c	src/butpixel.c	src/controleview.c	src/coordinate.c	\
				src/mlx_conig.c	src/parsing.c	src/utils.c	FDF.c	gnl/get_next_line.c	\
				gnl/get_next_line_utils.c	src/ft_printf.c	src/ft_hexconv.c src/ft_utils.c


OBJS		=	$(SRCS:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_A) $(MLX_A)
				@$(CC) $(CFLAGS) $(OBJS) $(SRC) $(LIBFT_A) $(MLX_A) -framework OpenGL -framework AppKit -o $(NAME)
				@echo "Linked into executable \033[0;32mfdf\033[0m."

$(LIBFT_A):
				@$(MAKE) -s -C $(LIBFT)
				@echo "Compiled $(LIBFT_A)."

$(MLX_A):
				@$(MAKE) -s -C $(MLX)
				@echo "Compiled $(MLX_A)."

bonus:			all

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
				@echo "Compiling $<."

localclean:
				@$(RM) $(OBJS)
				@echo "Removed object files."

clean:			localclean
				@$(MAKE) clean -s -C $(LIBFT)
				@echo "Clean libft."
				@$(MAKE) clean -s -C $(MLX)
				@echo "Clean gnl."

fclean:			localclean
				@$(MAKE) fclean -s -C $(LIBFT)
				@echo "Full clean libft."
				@$(MAKE) clean -s -C $(MLX)
				@echo "Clean mlx."
				@$(RM) $(NAME)
				@echo "Removed executable."

re:				fclean all

.PHONY:			all clean fclean re localclean bonus

$(NAME) : all