CC = gcc
CFLAGS = -std=c99
LDFLAGS = -lm

OBJ = main.o
SRC = $(OBJ:%.o=%.c)

all: $(OBJ)
	$(CC) $(OBJ) -o run.out $(LDFLAGS)
	rm *.o
omp:
	$(CC) $(CFLAGS) -fopenmp $(SRC) -o omp.out $(LDFLAGS) -fopenmp 

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.out
