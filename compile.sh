#!/bin/sh
#make -C libft/ fclean && make -C libft/
gcc -g -Wall -Wextra -Werror -o get_next_line.o -c get_next_line.c -D BUFFER_SIZE=64
gcc -g -Wall -Wextra -Werror -o main.o -c main.c
gcc -g -Wall -Wextra -Werror -o get_next_line_utils.o -c get_next_line_utils.c
#gcc -o alloc-wrap.o -c alloc-wrap.c
gcc -o test_gnl main.o get_next_line.o get_next_line_utils.o -g -Wall -Werror -Wextra -D BUFFER_SIZE=32
