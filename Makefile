FLAGS = -ansi -Wall -Wextra -Werror -pedantic-errors
LIBS = -lm

all: MatrixAndVectorOps.o input.o cluster
linuxClean:
	rm -rf *.o
	rm cluster
winClean:
	del *.o
	del cluster.exe
cluster: cluster.o MatrixAndVectorOps.o input.o modularity.o Algorithms.o MathHelpers.o eigen.o sparse.o spmat.o List.o
	gcc cluster.o MatrixAndVectorOps.o input.o modularity.o Algorithms.o MathHelpers.o eigen.o sparse.o spmat.o List.o -o cluster $(LIBS)
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
modularity: modularity.o
	gcc modularity.o -o modularity $(LIBS)
modularity.o: modularity.c
	gcc $(FLAGS) -c modularity.c
Algorithms: Algorithms.o
	gcc Algorithms.o -o Algorithms $(LIBS)
Algorithms.o: Algorithms.c
	gcc $(FLAGS) -c Algorithms.c
MathHelpers: MathHelpers.o
	gcc MathHelpers.o -o MathHelpers $(LIBS)
MathHelpers.o: MathHelpers.c
	gcc $(FLAGS) -c MathHelpers.c
eigen: eigen.o
	gcc eigen.o -o eigen $(LIBS)
eigen.o: eigen.c
	gcc $(FLAGS) -c eigen.c
sparse: sparse.o
	gcc sparse.o -o sparse $(LIBS)
sparse.o: sparse.c
	gcc $(FLAGS) -c sparse.c
spmat: spmat.o
	gcc spmat.o -o spmat $(LIBS)
spmat.o: spmat.c
	gcc $(FLAGS) -c spmat.c
List: List.o
	gcc List.o -o List $(LIBS)
List.o: List.c
	gcc $(FLAGS) -c List.c