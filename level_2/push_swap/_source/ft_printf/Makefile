## VARIABLES

NAME = libftprintf.a

# Path to libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Mandatory sources
SRCS =	ft_printf.c \
				ft_handle_percent.c \
				ft_handle_char.c \
				ft_handle_str.c \
				ft_handle_int.c \
				ft_handle_ptr.c \
				ft_handle_u.c \
				ft_handle_x.c \
				ft_parse.c 

OBJS = $(SRCS:.c=.o)

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Colors
GREEN = \\033[0;32m
YELLOW = \\033[0;33m
RESET = \\033[0m

#COMMANDS

#Build Libft first
all:
	@printf "$(GREEN)Starting build...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) $(NAME)
	@printf "$(GREEN)Build complete!$(RESET)"

# Build Rule for .o files 
%.o: %.c 
	@printf "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

#Start Building 
$(NAME): $(OBJS) $(LIBFT)
	@printf "$(YELLOW)Creating $(NAME)...$(RESET)"
	cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)

clean:
	@printf "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@printf "$(YELLOW)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all
