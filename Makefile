CFLAGS = -Wall -Wextra -Werror

SRC_DIR=src

LIBFT_DIR=libft

SRC_FILES = $(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/normalize.c \
		$(SRC_DIR)/parse.c \
		$(SRC_DIR)/print.c \
		$(SRC_DIR)/utils.c

SRCS_OBJ = $(SRC_FILES:.c=.o)

BONUS_OBJ = $(BONUS_FILES:.c=.o)

$(LIBFT_FILES):.c=.o

ALL_OBJ = $(SRCS_OBJ) $(BONUS_OBJ)

DFILES = $(ALL_OBJ:.o=.d)

NAME = libftprintf.a

NAME_LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME) : $(NAME_LIBFT) $(SRCS_OBJ)
	ar rcs $(NAME) $(SRCS_OBJ)

$(NAME_LIBFT):
	make -C $(LIBFT_DIR) bonus

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) -MMD -MP $< -o $@ -llibft/libft

clean:
	rm -rf $(ALL_OBJ) $(DFILES) $(NAME_LIBFT)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re

-include : $(DFILES)
