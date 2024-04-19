CC=gcc
CFLAGS=-pthread -std=c99

SRCS = merge_sort.c main.c
OBJS = $(SRCS:.c=.o)

all: test

test: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o test

merge_sort.o: merge_sort.c merge_sort.h
	$(CC) $(CFLAGS) -c merge_sort.c

main.o: main.c merge_sort.h
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean

clean:
	rm -f *.o test
