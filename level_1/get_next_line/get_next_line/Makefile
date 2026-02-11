NAME = get_next_line
CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE ?= 42

SRC = get_next_line.c \
	get_next_line_utils.c
OBJ = $(SRC:.c=.o)

BONUS_SRC = get_next_line_bonus.c \
	get_next_line_utils_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(OBJ) -o $(NAME)

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(BONUS_OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
