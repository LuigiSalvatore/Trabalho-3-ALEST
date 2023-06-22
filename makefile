#Luigi Salvatore Bos-Mikich 22/06/2023

APPLICATIVO = app
CFLAGS = -c -std=c++11
MAIN_NAME = main
DASHOES = ${MAIN_NAME}.o WordTree.o Palavra.o splitCSV.o
NomeDoAPP = ${APPLICATIVO}
all:			${APPLICATIVO}

${APPLICATIVO}:	${DASHOES}
	g++ -o ${APPLICATIVO} ${DASHOES}

${MAIN_NAME}.o: 		${MAIN_NAME}.cpp WordTree.cpp WordTree.hpp Palavra.cpp Palavra.hpp splitCSV.cpp splitCSV.hpp
	g++ ${CFLAGS} ${MAIN_NAME}.cpp

WordTree.o: 			WordTree.cpp WordTree.hpp
	g++ ${CFLAGS} WordTree.cpp

Palavra.o: 				Palavra.cpp Palavra.hpp
	g++ ${CFLAGS} Palavra.cpp

splitCSV.o: 			splitCSV.cpp splitCSV.hpp
	g++ ${CFLAGS} splitCSV.cpp

run:			${APPLICATIVO} 
	./${APPLICATIVO}

clean: 			
	del ${DASHOES} ${APPLICATIVO}