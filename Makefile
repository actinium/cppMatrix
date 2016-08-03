CXX=clang++
CXXFLAGS= -Wall -std=c++11

test_matrix:test/test_matrix.cpp
	$(CXX) $(CXXFLAGS) -o test_matrix test/test_matrix.cpp

.PHONY: run-test
run-test: test_matrix
	@./test_matrix

.PHONY: clean
clean:
	rm -rf test_matrix
