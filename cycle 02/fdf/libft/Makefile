# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 10:37:51 by zsid-ele          #+#    #+#              #
#    Updated: 2025/01/29 09:39:28 by zsid-ele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	= ft_isalpha.c		ft_isdigit.c		ft_isalnum.c	\
		  ft_isascii.c		ft_isprint.c		ft_strlen.c     \
		  ft_memset.c		ft_bzero.c			ft_memcpy.c     \
		  ft_memmove.c		ft_strlcpy.c		ft_strlcat.c    \
		  ft_toupper.c		ft_tolower.c		ft_strchr.c     \
		  ft_strrchr.c		ft_strncmp.c		ft_memchr.c     \
		  ft_memcmp.c		ft_strnstr.c		ft_atoi.c       \
		  ft_calloc.c		ft_strdup.c			ft_substr.c     \
		  ft_strjoin.c		ft_strtrim.c		ft_split.c      \
		  ft_itoa.c			ft_strmapi.c		ft_striteri.c   \
		  ft_putchar_fd.c	ft_putstr_fd.c		ft_putendl_fd.c\
		  ft_putnbr_fd.c

BSOURCE	= ft_lstnew.c 		ft_lstadd_front.c	ft_lstsize.c	\
		  ft_lstlast.c		ft_lstadd_back.c	ft_lstdelone.c	\
		  ft_lstclear.c		ft_lstiter.c		ft_lstmap.c		\

OBJS		= ${SOURCES:%.c=%.o}

BOBJS		= ${BSOURCE:%.c=%.o}

ARC			= ar rcs

CC			= cc

C 			= -c #for not linking the files #

FLAGS		= -Wall -Wextra -Werror

file		= libft.a

all:	${file} 

${file}: ${SOURCES} ${OBJS}
		${CC} ${FLAGS} ${C} ${SOURCES}
		${ARC} ${file} ${OBJS}
bonus: ${file} ${BSOURCE} ${BOBJS}
		${CC} ${FLAGS} ${C} ${BSOURCE}
		${ARC} ${file} ${BOBJS}
fclean: clean
	rm -f ${file}
clean:
	rm -f ${OBJS}
re: fclean all
