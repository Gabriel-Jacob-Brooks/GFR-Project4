all: test-example test main

# Example test executable - must compile bst.cpp directly in the command
test-example: test_bst_example.cpp usecase.cpp bst.h bst.cpp binhex.txt
	g++ -std=c++11 test_bst_example.cpp bst.cpp -o test-example

# Real test executable
test: test_bst.cpp usecase.cpp bst.h bst.cpp binhex.txt
	g++ -std=c++11 test_bst.cpp bst.cpp -o test

# Main executable
main: main.cpp bst.h bst.cpp
	g++ -std=c++11 main.cpp bst.cpp -o usecase

# Run tests
run-example: test-example
	./test-example

run-test: test
	./test

run-main: usecase
	./usecase

clean:
	rm -f *.o test test-example main usecase
