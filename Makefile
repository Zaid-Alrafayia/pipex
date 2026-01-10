NAME        = pipex
NAME_BONUS  = pipex_bonus

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = pipex.c \
              process.c \
              file_check.c \
              cmd.c \
              env_checker.c \
							path_check.c

SRCS_BONUS  = pipex_bonus.c \
              process_bonus.c \
              file_check_bonus.c \
              cmd_bonus.c \
              env_checker_bonus.c

OBJS        = $(SRCS:.c=.o)
OBJS_BONUS  = $(SRCS_BONUS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_DIR) fclean

re: fclean all

. PHONY: all clean fclean re bonus
