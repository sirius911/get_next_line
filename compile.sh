#!/bin/sh
BUFFER_SIZE=32
clang -g -Wall -Wextra -Werror -o get_next_line.o -c get_next_line.c -D BUFFER_SIZE=$BUFFER_SIZE
clang -g -Wall -Wextra -Werror -o main.o -c main.c -D BUFFER_SIZE=$BUFFER_SIZE
clang -g -Wall -Wextra -Werror -o get_next_line_utils.o -c get_next_line_utils.c
clang -o alloc-wrap.o -c alloc-wrap.c
if [ "$#" -eq  "0" ]; then
	clang -o test_gnl main.o get_next_line.o get_next_line_utils.o -g -Wall -Werror -Wextra  -ldl
else
	clang -o test_gnl main.o get_next_line.o get_next_line_utils.o alloc-wrap.o -g -Wall -Werror -Wextra  -ldl
fi
rm -f *.o
