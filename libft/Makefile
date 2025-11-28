# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/28 02:08:29 by zaalrafa          #+#    #+#              #
#    Updated: 2025/09/01 03:18:44 by zaalrafa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs

RM= rm -f
PRINTF_SRCS = ft_printf.c hexconvert.c point_conv.c print_num.c \
			 print_str.c print_unum.c ft_abs.c

SRCS = ft_itoa.c ft_split.c ft_strncmp.c \
	ft_atoi.c ft_memchr.c ft_strchr.c ft_strnstr.c \
	ft_bzero.c ft_memcpy.c ft_strdup.c ft_strrchr.c \
	ft_calloc.c  ft_memmove.c ft_striteri.c ft_strtrim.c \
	ft_isalnum.c  ft_memset.c ft_strjoin.c ft_substr.c \
	ft_isalpha.c  ft_putchar_fd.c ft_strlcat.c ft_tolower.c \
	ft_isascii.c  ft_putendl_fd.c ft_strlcpy.c ft_toupper.c \
	ft_isdigit.c  ft_putnbr_fd.c ft_strlen.c ft_memcmp.c \
	ft_isprint.c  ft_putstr_fd.c ft_strmapi.c ${PRINTF_SRCS}

SRCS_B = ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstmap_bonus.c \
	ft_lstnew_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c

OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

all: ${NAME}

bonus:	${OBJS_B}
		${AR} ${NAME} ${OBJS_B}

clean:
	${RM} ${OBJS} ${OBJS_B}

$(OBJS) $(OBJS_B): libft.h

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
