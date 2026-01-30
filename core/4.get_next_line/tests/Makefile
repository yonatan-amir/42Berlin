NAME = gnl_test
EDGE_NAME = gnl_edge_test
CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE ?= 42

SRC = main.c ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c
OBJ = $(SRC:.c=.o)

EDGE_SRC = edge_test.c ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c
EDGE_OBJ = $(EDGE_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(OBJ) -o $(NAME)

edge: $(EDGE_NAME)

$(EDGE_NAME): $(EDGE_OBJ)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(EDGE_OBJ) -o $(EDGE_NAME)

clean:
	rm -f $(OBJ) $(EDGE_OBJ)

fclean: clean
	rm -f $(NAME) $(EDGE_NAME)

re: fclean all

.PHONY: all edge clean fclean re
