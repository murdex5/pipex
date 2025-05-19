# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadferna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 15:37:19 by kadferna          #+#    #+#              #
#    Updated: 2024/12/18 15:37:23 by kadferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF_SRC_DIR = ../ft_printf
GNL_SRC_DIR = ../get_next_line

SRCS		= ft_atoi.c  ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_putnbr_base.c \
			  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRC_PRINTF = $(PRINTF_SRC_DIR)/utils0.c $(PRINTF_SRC_DIR)/utils1.c $(PRINTF_SRC_DIR)/utils2.c $(PRINTF_SRC_DIR)/utils3.c $(PRINTF_SRC_DIR)/utils4.c \
			 $(PRINTF_SRC_DIR)/printf_utils.c $(PRINTF_SRC_DIR)/ft_printf.c 

SRC_GNL = $(GNL_SRC_DIR)/get_next_line.c $(GNL_SRC_DIR)/get_next_line_bonus.c

OBJS		= ${SRCS:.c=.o}
OBJS_PRINTF = ${SRC_PRINTF:.c=.o}
OBJS_GNL	= ${SRC_GNL:.c=.o}
NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

$(NAME): $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL)
	ar rcs $(NAME) $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re