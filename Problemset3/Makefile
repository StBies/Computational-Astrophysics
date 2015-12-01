CC = g++
CFLAGS = -std=c++11 -O3
LDFLAGS = -LM

OBJ = main.o CelBody.o Planet.o Star.o PhysSim.o constants.o

SRC = $(OBJ:%.o=%.cpp)

all: $(OBJ)
	$(CC) $(OBJ) -o simul.out $(LDFLAGS)
	rm *.o

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.out  
