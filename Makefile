CC = gcc
SRC_PATH = ./srcs
SRCS = ${SRC_PATH}/utils.c \
		${SRC_PATH}/utils1.c \
		${SRC_PATH}/utils2.c \
		${SRC_PATH}/checks.c \
		${SRC_PATH}/errors.c \
		${SRC_PATH}/parse.c \
		${SRC_PATH}/free.c \
		${SRC_PATH}/exec.c \
		${SRC_PATH}/main.c 
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Werror -Wextra
LIBFT_PATH = ./libft
LIBFT_LIB = ${LIBFT_PATH}/libft.a
NAME = pipex


all: subsystems $(NAME) 

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

subsystems:
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re subsytems