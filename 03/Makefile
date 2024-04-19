CC=gcc
CFLAGS=-Wall -std=c99

SRCS = main.c sort.c
OBJS = $(SRCS:.c=.o)
EXEC = program.out

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

main.o: main.c sort.h
	$(CC) $(CFLAGS) -c main.c

sort.o: sort.c sort.h
	$(CC) $(CFLAGS) -c sort.c

.PHONY: clean

clean:
	rm -f *.out $(EXEC) *.o
