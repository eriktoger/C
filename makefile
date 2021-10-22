PROBLEM = 466A-Cheap-travel
DIR = ./CodeForces/1200
SOURCES = ${DIR}/${PROBLEM}/${PROBLEM}.c ${DIR}/${PROBLEM}/TEST-${PROBLEM}.c 
INCLUDES = -I ${DIR}/${PROBLEM} 

# make test && ./test.out
test:  ${SOURCES}
	gcc -o test.out ${SOURCES} ${INCLUDES}

#make main && ./main.out
#main should be self sufficent to pass the online judge.
main:  ${DIR}/${PROBLEM}/main.c 
	gcc -o main.out  ${DIR}/${PROBLEM}/main.c 


