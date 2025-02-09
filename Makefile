# Name of the executable
NAME = push_swap

# Colours 
RESET 	= \033[0m
RED 	= \033[0;31m
BRED 	= \033[1;31m
GREEN 	= \033[0;32m
BGREEN 	= \033[1;32m
PURPLE 	= \033[0;35m
BPURPLE	= \033[1;35m
BLUE 	= \033[0;34m
BBLUE 	= \033[1;34m
CYAN 	= \033[0;36m
BCYAN 	= \033[1;36m
WHITE 	= \033[0;97m
BWHITE 	= \033[1;97m
YELLOW 	= \033[0;33m
BYELLOW = \033[1;33m

# FLAGS
CFLAGS = -g -Wall -Werror -Wextra -fsanitize=address

# Sources
SRCS = SRC/push_swap.c SRC/check_error_free.c SRC/path_to_sort.c SRC/algo.c SRC/utils.c SRC/utils_extra.c SRC/push.c SRC/swap.c SRC/rotate.c SRC/reverse.c 

# Objects
OBJS = $(SRCS:.c=.o)

# Headers
HD = push_swap.h
HDLBFT = ./LIBFT/libft.h
HDPF = ./LIBFT/ft_printf.h
HDGNL = ./LIBFT/get_next_line.h

# Lib
LLibft = ./LIBFT/libft.a

# Rules

# Target default (when you do make)
all: libft $(NAME) 
 
# Create executable PUSH_SWAP and compile
$(NAME): $(SRCS) $(OBJS) $(LLibft)
	@echo "\n$(BGREEN)| Compiled >>> [PUSH_SWAP] | $(RESET)\n"
	cc $(CFLAGS) $(SRCS) $(LLibft) -o $(NAME)
	
# Take .c, generate .o
%.o: %.c $(HD) $(HDLBFT) $(HDPF) $(HDGNL) Makefile
	cc $(CFLAGS) -c $< -o $@

# Makfile LIBFT+PRINTF+GNL
libft:
	cd ./LIBFT && make
	
# Clean .o files
clean:
	rm -f $(OBJS)
	$(MAKE) -C ./LIBFT clean

# Make clean + delete binary (executable)
fclean: clean
	rm -f $(NAME)
	@echo "$(BRED)| Deleted >>> [PUSH_SWAP] | $(RESET)\n"
	$(MAKE) -C ./LIBFT fclean

# Fclean and make all again
re: fclean all
	@echo "$(BWHITE)| Redone >>> [PUSH_SWAP][LIBFT][GET_NEXT_LINE][PRINTF] | $(RESET)\n"
	
# Always execute this rules, good practice
.PHONY: all clean fclean re libft
