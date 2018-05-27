NAME = gnl
CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME) 

$(NAME):
		$(CC) $(CFLAGS) -I libft/ -o get_next_line.o -c get_next_line.c
		$(CC) $(CFLAGS) -I libft/ -o main.o -c main.c
		$(CC) -o $(NAME) main.o get_next_line.o -I libft/ -L libft/ -lft

clean:
		/bin/rm -rf *.o

fclean: clean
		/bin/rm -rf $(NAME)

re: fclean all
