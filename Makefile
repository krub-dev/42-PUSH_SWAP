# Name of the executable
NAME = push_swap.a

# FLAGS
CFLAGS = -Wall -Werror -Wextra

# Sources
SRCS = SRC/push_swap.c SRC/check_error_free.c SRC/path_to_sort.c SRC/algo.c SRC/utils.c SRC/utils_extra.c SRC/push.c SRC/swap.c SRC/rotate.c SRC/reverse.c 

# Objects
OBJS = $(SRCS:.c=.o)

# Headers
HD = push_swap.h

# Rules

# Target default (when you do make)
all: $(NAME)

# Create the library and compile
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) 

# Take .o, generate .c
%.o: %.c $(HD) Makefile
	gcc $(CFLAGS) -c $< -o $@

# Executable PUSH_SWAP
ex:
	gcc -g -Werror -Wextra -Wall $(SRCS) ./LIBFT/libft.a -o push_swap

# Makfile LIBFT+extras
libft:
	cd ./LIBFT && make
	
# Clean .o files
clean:
	rm -f $(OBJS)

# Make clean, delete binary(executable)
fclean: clean
	rm -f $(NAME)

# Fclean and make again
re: fclean all
	
# Always execute this rules, good practice
.PHONY: all clean fclean re ex libft
