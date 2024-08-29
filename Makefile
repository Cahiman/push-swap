NAME = push_swap

C_FILES =	main.c\
		check_args.c\
		free_errors.c\
		init_list.c\
		swap.c\
		utils.c\
		rotate.c\
		three_node_algo.c\
		reverse.c\
		big_algo.c\
		big_algo_prep.c\
		push.c\


SRCS = $(addprefix srcs/,$(C_FILES))

CFLAGS = -Wall -Werror -Wextra -I include/ -g

LIB = libft/libft.a printf/libftprintf.a
DEPS = $(addprefix libs/,$(LIB))

all: ${NAME}

${NAME}: ${SRCS}
	make -C libs/libft
	make -C libs/printf
	cc ${CFLAGS} ${SRCS} -o ${NAME} ${DEPS}

clean:
	make -C libs/libft clean
	make -C libs/printf clean

fclean:	clean
		rm -rf ${NAME}

re:             fclean all

.PHONY:         all clean fclean re