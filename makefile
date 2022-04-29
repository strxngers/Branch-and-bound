all: test_Cost Main

test_Cost: Cost.o test_Cost.cpp
	g++ -o test_Cost Cost.o test_Cost.cpp

Cost.o: Cost.cpp Cost.h
	g++ -c Cost.cpp

Assignament.o: Assignament.cpp Assignament.h
	g++ -c Assignament.cpp

Main: Assignament.o Cost.o Main.cpp
	g++ Assignament.o Cost.o Main.cpp -o main

clean:
	rm -f *.o test_Cost

run all: Main
	./main