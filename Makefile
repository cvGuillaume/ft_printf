CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
INC = -I./includes
SRCS =			srcs/ft_printf.c \
				srcs/ft_utils.c \
				srcs/ft_utils2.c \
				srcs/ft_utils3.c \
				srcs/ft_print_c.c \
				srcs/ft_print_s.c \
				srcs/ft_print_d_i.c \
				srcs/ft_print_u.c \
				srcs/ft_print_x.c \
				srcs/ft_print_p.c \
				srcs/ft_print_pct.c
OBJS = 			${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c ${INC} $< -o ${<:.c=.o}

${NAME}: ${LIBFT} ${OBJS}
	ar rc ${NAME} ${OBJS} $(shell find libft -name '*.o')
	ranlib ${NAME}

${LIBFT}:
	@make all -C libft

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	@make clean -C libft
	rm -f ${NAME}
	rm -f ${LIBFT}

re: fclean all

.PHONY: all clean fclean re