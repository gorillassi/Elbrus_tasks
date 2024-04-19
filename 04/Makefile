CC=gcc
CFLAGS=-Wall -std=c99

SRCS = main.c
OBJS = $(SRCS:.c=.o)
EXEC = main.out

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean

clean:
	rm -f *.out $(EXEC) *.o
