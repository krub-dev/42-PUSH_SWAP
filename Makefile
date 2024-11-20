# Name of the executable
NAME = push_swap.a

# FLAGS
CFLAGS = -Wall -Werror -Wextra

# Sources
SRCS = ./*.c

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
	cc $(CFLAGS) -c $< -o $@


# Clean .o files
clean:
	rm -f $(OBJS)

# Make clean, delete binary(executable)
fclean: clean
	rm -f $(NAME)

# Fclean and make again
re: fclean all
	
# Always execute this rules, good practice
.PHONY: all clean fclean re
