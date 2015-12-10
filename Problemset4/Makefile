CC = gcc
CFLAGS = -std=c99
LDFLAGS = -lm

OBJ = main.o

all: $(OBJ)
	$(CC) $(OBJ) -o run.out $(LDFLAGS)
	rm *.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.out
