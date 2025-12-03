CFLAGS = -Wall -Wextra -Werror

SRC_DIR=src

TESTS_DIR=tests

INCLUDES=headers

SRC_FILES = $(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/normalize.c \
		$(SRC_DIR)/parse.c \
		$(SRC_DIR)/print.c \
		$(SRC_DIR)/utils.c

TESTS_FILES = $(TESTS_DIR)/main.c \
		$(TESTS_DIR)/tests_mandatory.c

SRCS_OBJ = $(SRC_FILES:.c=.o)

BONUS_OBJ = $(BONUS_FILES:.c=.o)

ALL_OBJ = $(SRCS_OBJ) $(BONUS_OBJ)

DFILES = $(ALL_OBJ:.o=.d)

NAME = libftprintf.a

NAME_TESTS = tests-libftprintf.o

all: $(NAME)

run-tests: tests
	./$(NAME_TESTS)

debug-tests: tests
	gdb ./$(NAME_TESTS)

tests: $(NAME_TESTS)

$(NAME_TESTS) : $(SRC_FILES) $(TESTS_FILES)
	$(CC) $(CFLAGS) -g3 $(TESTS_FILES) $(SRC_FILES) -o $(NAME_TESTS) -I$(INCLUDES)

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
