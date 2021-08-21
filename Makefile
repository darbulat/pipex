SRCS 		= 	main.c utils.c
LIB			=	libft/libft.a
NAME		= 	pipex
INCS		=	libft -I ./
GCC			=	gcc
CHECKER		=	checker
CFLAGS		=	-Werror -Wextra -Wall
RM			=	rm -f
OBJS		=	$(SRCS:.c=.o)
HEADERS		= 	pipex.h

all:			${NAME}

%.o: %.c
	${GCC} ${CFLAGS} -c $< -o $@

${NAME}: $(HEADERS) $(OBJS)
	@make -C ./libft
	${GCC} ${OBJS} ${LIB} -I${INCS} -o ${NAME}

clean:
				${RM} ${OBJS}
				@make clean -C ./libft

fclean:			clean
				${RM} ${NAME}
				@make fclean -C ./libft

re:				fclean all
.PHONY:
				all, fclean, clean, re