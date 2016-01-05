CC = gcc
CFLAGS = -std=c99 -O3
LDFLAGS = -lm

OBJ = main.o mc-integrator.o
SRC = $(OBJ:%.o=%.c)

all: $(OBJ)
	make prog
	make omp
	make gsl
	make ompgsl
prog: $(OBJ)
	$(CC) $(OBJ) -o run.out $(LDFLAGS)
	rm *.o
omp:
	$(CC) $(CFLAGS) -fopenmp $(SRC) -o omp.out $(LDFLAGS) -fopenmp 
gsl:
	$(CC) $(CFLAGS) -D gsl $(SRC) -L/usr/include/ -lgsl -lgslcblas $(LDFLAGS) -o gsl.out
ompgsl:
	$(CC) $(CFLAGS) -D gsl -fopenmp $(SRC) -o ompgsl.out $(LDFLAGS) -fopenmp -lgsl -lgslcblas
%.o: %.c
	$(CC) $(CFLAGS) -c $<

plot:
	gnuplot plots/plotscript.plt

clean:
	rm *.out
