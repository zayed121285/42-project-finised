
CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

C		= -c

NAME	= libft.a

LFLAGS	= ar rcs

 

BSOURCE	= ft_lstnew.c 		ft_lstadd_front.c	ft_lstsize.c	\
		  ft_lstlast.c		ft_lstadd_back.c	ft_lstdelone.c	\
		  ft_lstclear.c		ft_lstiter.c		ft_lstmap.c		\

OBJS	= ${SOURCE:%.c=%.o}

BOBJS	= ${BSOURCE:%.c=%.o}

all:	${NAME}


${NAME}: ${SOURCE} ${OBJS}
	${CC} ${CFLAGS} ${C} ${SOURCE}
	${LFLAGS} ${NAME} ${OBJS}

bonus: ${NAME} ${BOBJS} ${BSOURCE}
	${CC} ${CFLAGS} ${C} ${BSOURCE}
	${LFLAGS} ${NAME} ${BOBJS}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all
