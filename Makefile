CXX=clang++
CXXFLAGS= -I$(INCDIR) -Wall -std=c++11

INCDIR=include

test_matrix:test/test_matrix.cpp
	$(CXX) $(CXXFLAGS) -o test_matrix test/test_matrix.cpp

.PHONY: run-test
run-test: test_matrix
	@./test_matrix

.PHONY: clean
clean:
	rm -rf test_matrix
