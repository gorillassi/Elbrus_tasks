CC = gcc
CFLAGS = -Wall 

all: first_user second_user

first_user: first_user.c
	$(CC) $(CFLAGS) first_user.c -o first_user.out

second_user: second_user.c
	$(CC) $(CFLAGS) second_user.c -o second_user.out

.PHONY: clean

clean:
	rm -f first_user second_user
