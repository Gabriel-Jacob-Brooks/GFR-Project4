all: main

main: test_bst.o usecase.o 
	g++ -std=c++11 test_bst.o -o test

main.o:  main.cpp bst.h
	g++ -std=c++11 -c main.cpp


usecase.o: usecase.cpp bst.h
	g++ -std=c++11 -c usecase.cpp


test_bst.o: test_bst.cpp bst.h 
	g++ -std=c++11 -c test_bst.cpp

clean:
	rm -f *.o test
