# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 12:32:33 by zsid-ele          #+#    #+#              #
#    Updated: 2025/03/02 09:33:45 by zsid-ele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: server client
	@echo "\033[3;31mEverything\033[0m   \033[3;36mis Ready\033[0m"

bonus: server client

server: server.o libft
	@$(CC) -o $@ $< -Llibft -lft
		@echo "\033[3;35mThe_file_is_ready\033[0m   \033[3;32mserver\033[0m"

client: client.o libft
	@$(CC) -o $@ $< -Llibft -lft
	@echo "\033[3;35mThe_file_is_ready\033[0m   \033[3;32mclient\033[0m"

%.o: %.c
	@$(CC) -c $(CFLAGS) $?

libft:
	@make -C libft

clean:
	@rm -f $(OBJECTS)
	@make -C libft clean
	@echo "\033[3;31mclean\033[0m   \033[3;36mDone\033[0m"
	
fclean: clean
	@rm -f server client libft/libft.a
	@echo "\033[3;31mfclean\033[0m   \033[3;36mDone\033[0m"

re: @fclean all

.PHONY: all bonus libft clean fclean re
