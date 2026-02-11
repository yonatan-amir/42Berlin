## VARIABLES

NAME = libft.a

# Mandatory sources
SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c

# Bonus sources
BONUS = ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c

# Object files
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS:.c=.o)

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Colors
GREEN = \\033[0;32m
YELLOW = \\033[0;33m
RESET = \\033[0m


## RULES

all: 
	@echo "$(GREEN)Starting build...$(RESET)"
	@$(MAKE) $(NAME)
	@echo "$(GREEN)Build complete!$(RESET)"

$(NAME): $(OBJS)
	@echo "$(YELLOW)Creating $(NAME)...$(RESET)"
	@ar rcs $(NAME) $(OBJS)

# Build rule for .o files
%.o: %.c libft.h
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Bonus rule (adds bonus objs to the library)
bonus: $(OBJS) $(OBJS_BONUS)
	@echo "$(YELLOW)Adding bonus files...$(RESET)"
	@ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)
	@echo "$(GREEN)Bonus build complete!$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@echo "$(YELLOW)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all
