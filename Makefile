FLAGS = -ansi -Wall -Wextra -Werror -pedantic-errors
LIBS = -lm

all: MatrixAndVectorOps.o input.o cluster
clean:
	rm -rf *.o
	rm cluster

cluster: cluster.o MatrixAndVectorOps.o input.o
	gcc cluster.o MatrixAndVectorOps.o input.o -o cluster $(LIBS)
cluster.o: cluster.c
	gcc $(FLAGS) -c cluster.c

MatrixAndVectorOps: MatrixAndVectorOps.o
	gcc MatrixAndVectorOps.o -o MatrixAndVectorOps $(LIBS)
MatrixAndVectorOps.o: MatrixAndVectorOps.c
	gcc $(FLAGS) -c MatrixAndVectorOps.c

input: input.o
	gcc input.o -o input $(LIBS)
input.o: input.c
	gcc $(FLAGS) -c input.c
