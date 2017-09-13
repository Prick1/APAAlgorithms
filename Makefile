all: sorts

algorithms.o: algorithms.cpp algorithms.h
	@g++ -Wall -c algorithms.cpp -O3 -std=c++11

main.o: main.cpp algorithms.h
	@g++ -Wall -c main.cpp -O3 -std=c++11

sorts: algorithms.o main.o
	@echo para executar os sorts em cima de um arquivo, digite: \""./sorts.out <nomedoarquivo>"\"
	@echo digite \"make clean\" para remover executaveis e semelhantes
	@g++ -Wall algorithms.o main.o -o sorts.out -O3 -std=c++11
	

.PHONY: clean

clean:
	rm *.o *.out ?+?S@???@8




