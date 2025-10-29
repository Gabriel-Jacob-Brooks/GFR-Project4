all: main

main: bst.o usecase.o main.o
	g++ -std=c++11 bst.o main.o -o testmain


main.o:  main.cpp bst.h
	g++ -std=c++11 -c main.cpp


usecase.o: usecase.cpp bst.h
	g++ -std=c++11 -c usecase.cpp


# bst.o: test_bst_example.cpp bst.h
# 	g++ -std=c++11 -c test_bst_example.cpp

test_bst.o: test_bst.cpp bst.h
	g++ -std=c++11 -c test_bst.cpp

clean:
	rm -f *.o test
