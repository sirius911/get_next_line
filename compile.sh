#!/bin/sh
#make -C libft/ fclean && make -C libft/
gcc -Wall -Wextra -Werror -o get_next_line.o -c get_next_line.c -D BUFFER_SIZE=32
gcc -Wall -Wextra -Werror -o main.o -c main.c
gcc -Wall -Wextra -Werror -o get_next_line_utils.o -c get_next_line_utils.c
gcc -o alloc-wrap.o -c alloc-wrap.c
gcc -o test_gnl main.o get_next_line.o get_next_line_utils.o alloc-wrap.o -D BUFFER_SIZE=32

