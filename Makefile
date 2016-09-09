CXX=clang++
CXXFLAGS= -I$(INCDIR) -Wall -std=c++11

INCDIR=include
TESTDIR=test

test_matrix:$(TESTDIR)/test_matrix.cpp $(INCDIR)/matrix.h
	$(CXX) $(CXXFLAGS) -o test_matrix $(TESTDIR)/test_matrix.cpp

.PHONY: run-test
run-test: test_matrix
	@./test_matrix

.PHONY: clean
clean:
	rm -rf test_matrix
