CC = g++
CFLAGS = -O3 -std=c++11
LDFLAGS = -lm -lgsl -lgslcblas

OBJ = main.o Data.o Processor.o

prog: $(OBJ)
	$(CC) $(OBJ) -o run.out $(LDFLAGS)
	rm *.o
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
clean:
	rm *.out 
