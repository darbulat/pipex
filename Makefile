SRCS 		= 	main.c utils.c libft/libft.a
NAME		= 	pipex
INCS		=	libft -I ./
GCC			=	gcc
CHECKER		=	checker
CFLAGS		=	-Werror -Wextra -Wall
RM			=	rm -f

all:			${NAME}

${NAME}:
	@make -C ./libft
	${GCC} ${SRCS} -I${INCS} -o ${NAME}

clean:
				@${RM} @${NAME}
				@make clean -C ./libft

fclean:			clean
				${RM} ${NAME}
				@make fclean -C ./libft

re:				fclean all
.PHONY:
				all, fclean, clean, re