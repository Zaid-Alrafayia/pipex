NAME = libex.a

CC = cc
CFLAGS = -g -Wall -Werror -Wextra -I. -I./libft

AR = ar rcs
RM = rm -f

SRCS = 

PRINT_SRCS = ft_printf.c hexconvert.c point_conv.c print_num.c \
			 print_str.c print_unum.c ft_abs.c
FT_SRCS = ft_itoa.c ft_split.c ft_strncmp.c \
	ft_atoi.c ft_memchr.c ft_strchr.c ft_strnstr.c \
	ft_bzero.c ft_memcpy.c ft_strdup.c ft_strrchr.c \
	ft_calloc.c  ft_memmove.c ft_striteri.c ft_strtrim.c \
	ft_isalnum.c  ft_memset.c ft_strjoin.c ft_substr.c \
	ft_isalpha.c  ft_putchar_fd.c ft_strlcat.c ft_tolower.c \
	ft_isascii.c  ft_putendl_fd.c ft_strlcpy.c ft_toupper.c \
	ft_isdigit.c  ft_putnbr_fd.c ft_strlen.c ft_memcmp.c \
	ft_isprint.c  ft_putstr_fd.c ft_strmapi.c


FT_OBJS = $(addprefix libft/, $(FT_SRCS:.c=.o))
OBJS = $(SRCS:.c=.o)

libft/%.o: libft/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

${NAME}: $(OBJS) $(FT_OBJS)
	$(AR) $(NAME) $(OBJS) $(FT_OBJS)

clean:
	$(RM) $(OBJS) $(FT_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
