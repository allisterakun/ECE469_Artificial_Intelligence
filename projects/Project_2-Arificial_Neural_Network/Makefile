main.out: main.o neuralNetwork.o
	g++ -o main.out main.o neuralNetwork.o
main.o:main.cpp neuralNetwork.hpp
	g++ -c main.cpp
neuralNetwork.o:neuralNetwork.cpp neuralNetwork.hpp
	g++ -c neuralNetwork.cpp
clean:
	rm *.out *.o *.stackdump *~
