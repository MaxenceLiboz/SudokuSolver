SRCS 		= srcs/ft_checks.c srcs/ft_sudoku.c srcs/ft_tab_functions.c

OBJS		= ${SRCS:.c=.o}

INCLUDES	= includes/ft.h

CC			= gcc

FLAGS		= -Wall -Wextra -Werror -fsanitize=address

NAME		= solver

RM			= rm -rf

all:		${NAME}

.c.o:		${INCLUDES}
			${CC} ${FLAGS} -I includes -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${INCLUDES}
			${CC} ${FLAGS} -I includes -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

