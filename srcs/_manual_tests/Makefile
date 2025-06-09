NAME = run_tests
SRC = tests.c
# SRC = tester.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra# -Werror

all: $(NAME)

$(NAME):
	$(CC) $(SRC) $(CFLAGS) -L.. -lftprintf -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
