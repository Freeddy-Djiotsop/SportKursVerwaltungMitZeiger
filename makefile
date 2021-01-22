clean: run
	rm -rf *.o
run: sportkurs
	./sportkurs

sportkurs: main.o sportkurs.o person.o
	g++ -Wall -std=c++11 main.o sportkurs.o person.o -o sportkurs

main.o: main.cpp
	g++ -Wall -std=c++11 -c main.cpp

sportkurs.o: sportkurs.cpp sportkurs.hpp
	g++ -Wall -std=c++11 -c sportkurs.cpp

person.o: person.cpp person.hpp
	g++ -Wall -std=c++11 -c person.cpp