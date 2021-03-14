checker: main.o checker.o agent.o
	g++ -std=c++17 -o checker main.o checker.o agent.o

main.o: main.cpp rang.hpp Game.hpp checker.hpp
	g++ -std=c++17 -c main.cpp

checker.o: checker.cpp checker.hpp
	g++ -std=c++17 -c checker.cpp

agent.o: agent.cpp agent.hpp checker.hpp
	g++ -std=c++17 -c agent.cpp

debug:
	g++ -std=c++17 -g -o checker main.cpp rang.hpp Game.hpp checker.hpp agent.hpp

clean:
	rm -f *.exe *.out *.o *.stackdump *~
	rm -f checker

backup:
	test -d backups || mkdir backups
	cp *.cpp backups
	cp *.h backups

