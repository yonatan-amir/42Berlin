## VARIABLES

NAME = push_swap

# Path to libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Mandatory sources
SRCS =	 \
				

OBJS = $(SRCS:.c=.o)

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Colors
GREEN = \\033[0;32m
YELLOW = \\033[0;33m
RESET = \\033[0m

#COMMANDS

#BUILD PLAN
all: $(NAME)

#Start Building 
$(NAME): $(OBJS) $(LIBFT)
	@echo "$(GREEN)Starting build...$(RESET)"
	@echo "$(YELLOW)Creating $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Build complete!$(RESET)"

## LIBFT RULES
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Build Rule for .o files 
%.o: %.c 
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(YELLOW)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all