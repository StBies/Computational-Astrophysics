CC = g++
CFLAGS = -O3 -std=c++11
LDFLAGS = -lm

OBJ = main.o Data.o

prog: $(OBJ)
	$(CC) $(OBJ) -o run.out $(LDFLAGS)
	rm *.o
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< 
