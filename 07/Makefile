CC=gcc
CFLAGS=-Wall

SRCS = main.c
OBJS = $(SRCS:.c=.o)
EXEC = program.out

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean

clean:
	rm -f *.out $(EXEC) *.o
