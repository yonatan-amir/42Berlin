## VARIABLES

# Name of the test runner executable
NAME = test_suite

# Path to libft
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

# Automatically detect all .c files in this directory
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Colors
GREEN = \\033[0;32m
YELLOW = \\033[0;33m
RESET = \\033[0m


## COMMANDS

# Default rule: build everything
all:
	@echo "$(GREEN)Starting test build...$(RESET)"
	@$(MAKE) $(NAME)
	@echo "$(GREEN)Tests ready: $(NAME)$(RESET)"

# Build final executable
$(NAME): $(OBJS) $(LIBFT)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Build libft
$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

# Compile .c to .o
%.o: %.c
	@echo "$(GREEN)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)

# Full clean
fclean: clean
	@echo "$(YELLOW)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

# Run the tests
run: $(NAME)
	@echo "$(GREEN)Running tests...$(RESET)"
	@./$(NAME)
