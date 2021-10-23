PROBLEM = 451B-Sort-The-Array
DIR = ./CodeForces/1300
SOURCES = ${DIR}/${PROBLEM}/${PROBLEM}.c ${DIR}/${PROBLEM}/TEST-${PROBLEM}.c 
INCLUDES = -I ${DIR}/${PROBLEM} 

# make test && ./test.out
test:  ${SOURCES}
	gcc -o test.out ${SOURCES} ${INCLUDES}

# make testDebug && gdb ./testDebug.out
testDebug:  ${SOURCES}
	gcc -g -o  testDebug.out ${SOURCES} ${INCLUDES}

#make main && ./main.out
#main should be self sufficent to pass the online judge.
main:  ${DIR}/${PROBLEM}/main.c 
	gcc -o main.out  ${DIR}/${PROBLEM}/main.c 


