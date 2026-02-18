NAME = gnl_test
EDGE_NAME = gnl_edge_test
CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE ?= 1025

SRC = main.c ../_source/get_next_line.c ../_source/get_next_line_utils.c
EDGE_SRC = edge_test.c ../_source/get_next_line.c ../_source/get_next_line_utils.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC) -o $(NAME)

edge: $(EDGE_NAME)

$(EDGE_NAME): $(EDGE_SRC)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(EDGE_SRC) -o $(EDGE_NAME)

clean:
	@true

fclean: clean
	rm -f $(NAME) $(EDGE_NAME)

re: fclean all

run: $(NAME) $(EDGE_NAME)
	@for f in files/*; do \
		echo BUFFER_SIZE "$(BUFFER_SIZE)\n" \
		echo "=== $$f ==="; \
		./$(NAME) "$$f"; \
	done
	@echo "=== edge ==="
	@./$(EDGE_NAME)

run-main: $(NAME)
	@for f in files/*; do \
		echo "=== $$f ==="; \
		./$(NAME) "$$f"; \
	done

run-edge: $(EDGE_NAME)
	@./$(EDGE_NAME)

.PHONY: all edge clean fclean re run run-main run-edge
