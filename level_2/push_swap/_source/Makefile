NAME      := push_swap
CC        := cc
CFLAGS    := -Wall -Wextra -Werror

RESET   := \033[0m
BLUE    := \033[1;34m
GREEN   := \033[1;32m
RED     := \033[1;31m

PRINTF_DIR := ft_printf
PRINTF     := $(PRINTF_DIR)/libftprintf.a

LIBFT_DIR := ft_printf/libft
LIBFT     := $(LIBFT_DIR)/libft.a

SRCS := push_swap.c \
				init_program.c \
				clean_program.c \
				sort.c \
				build_program.c \
				num_converter.c \
				parser.c \
				ops_swap.c \
				ops_push.c \
				ops_rotate.c \
				ops_r_rotate.c \

OBJS := $(SRCS:.c=.o)

.PHONY: all clean fclean re objs

all: $(NAME)

objs:
	@printf "$(BLUE)[INFO]$(RESET) Compiling sources\n"
	@$(MAKE) --no-print-directory $(OBJS) \
	&& printf "$(GREEN)[OK]$(RESET) Sources compiled\n" \
	|| { printf "$(RED)[FAIL]$(RESET) Source compilation failed\n"; exit 1; }

$(NAME): objs $(PRINTF) $(LIBFT)
	@printf "$(BLUE)[INFO]$(RESET) Linking $(NAME)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME) \
	&& printf "$(GREEN)[OK]$(RESET) Build complete: $(NAME)\n" \
	|| { printf "$(RED)[FAIL]$(RESET) Link failed: $(NAME)\n"; exit 1; }

$(PRINTF):
	@printf "$(BLUE)[INFO]$(RESET) Building ft_printf\n"
	@$(MAKE) -C $(PRINTF_DIR) \
	&& printf "$(GREEN)[OK]$(RESET) ft_printf ready\n" \
	|| { printf "$(RED)[FAIL]$(RESET) ft_printf build failed\n"; exit 1; }

$(LIBFT):
	@printf "$(BLUE)[INFO]$(RESET) Building libft\n"
	@$(MAKE) -C $(LIBFT_DIR) \
	&& printf "$(GREEN)[OK]$(RESET) libft ready\n" \
	|| { printf "$(RED)[FAIL]$(RESET) libft build failed\n"; exit 1; }

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(BLUE)[INFO]$(RESET) Cleaning objects\n"
	@rm -f $(OBJS) \
	&& printf "$(GREEN)[OK]$(RESET) Objects removed\n" \
	|| { printf "$(RED)[FAIL]$(RESET) Clean failed\n"; exit 1; }

fclean: clean
	@printf "$(BLUE)[INFO]$(RESET) Removing binary $(NAME)\n"
	@rm -f $(NAME) \
	&& printf "$(GREEN)[OK]$(RESET) Binary removed\n" \
	|| { printf "$(RED)[FAIL]$(RESET) fclean failed\n"; exit 1; }

re: fclean all
