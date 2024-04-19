CC=gcc
CFLAGS=-Wall
LDFLAGS=-lm

SRCS = functions.c main.c
OBJS = $(SRCS:.c=.o)
EXEC = matrix_multiplication

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC) $(LDFLAGS)

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean

clean:
	rm -f *.o $(EXEC)
