CC = gcc
CFLAGS = -std=c99 -O3
LDFLAGS = -lm

OBJ = main.o mc-integrator.o
SRC = $(OBJ:%.o=%.c)

all: $(OBJ)
	$(CC) $(OBJ) -o run.out $(LDFLAGS)
	rm *.o
omp:
	$(CC) $(CFLAGS) -fopenmp $(SRC) -o omp.out $(LDFLAGS) -fopenmp 
gsl:
	$(CC) $(CFLAGS) -D gsl $(SRC) -o gsl.out $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -c $<

plot:
	gnuplot plots/plotscript.plt

clean:
	rm *.out
