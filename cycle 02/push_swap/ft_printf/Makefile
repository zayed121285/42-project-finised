# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 12:54:47 by zsid-ele          #+#    #+#              #
#    Updated: 2025/01/14 11:20:29 by zsid-ele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

srcs = ft_printf.c ft_hexconv.c ft_utils.c

obj = ${srcs:%.c=%.o}

NAME = libftprintf.a

CC = cc

ar = ar rcs

flags = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${srcs} ${obj}
	${CC} ${flags} -c ${srcs}
	${ar} ${NAME} ${obj}
.c.o : 
	${CC} ${CFLAGS} -c $< -o $@ 

fclean:	clean
		rm -f ${NAME}

clean:
	rm -f ${obj}

re: fclean all