CFLAGS = -Wall -Wextra -Werror

SRC_DIR=src

INCLUDES=headers

SRC_FILES = $(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/normalize.c \
		$(SRC_DIR)/parse.c \
		$(SRC_DIR)/print.c \
		$(SRC_DIR)/utils.c

SRCS_OBJ = $(SRC_FILES:.c=.o)

BONUS_OBJ = $(BONUS_FILES:.c=.o)

ALL_OBJ = $(SRCS_OBJ) $(BONUS_OBJ)

DFILES = $(ALL_OBJ:.o=.d)

NAME = libftprintf.a

NAME_TESTS = tests-libftprintf.o

all: $(NAME)

tests: $(NAME_TESTS)

$(NAME_TESTS) : $(SRC_FILES) tests/main.c
	$(CC) $(CFLAGS) -g3 tests/main.c $(SRC_FILES) -o $(NAME_TESTS) -I$(INCLUDES)

$(NAME) : $(SRCS_OBJ)
	ar rcs $(NAME) $(SRCS_OBJ)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC)  -c $(CFLAGS) -MMD -MP $< -o $@ -I$(INCLUDES)

clean:
	rm -rf $(ALL_OBJ) $(DFILES) $(NAME_LIBFT)

fclean: clean
	rm -f $(NAME) $(NAME_TESTS)

re: fclean all

.PHONY: all bonus clean fclean re

-include : $(DFILES)
