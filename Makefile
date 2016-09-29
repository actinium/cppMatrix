CXX=clang++
CXXFLAGS= -I$(INCDIR) -Wall -std=c++11

INCDIR=include
TESTDIR=test

_INCLUDES= matrix.h \
           matrix_constructors_impl.h \
           matrix_assignment_impl.h \
           matrix_access_impl.h \
           matrix_modifires_impl.h \
           matrix_comparison_impl.h

INCLUDES=$(patsubst %,$(INCDIR)/%,$(_INCLUDES))

test_matrix:$(TESTDIR)/test_matrix.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) -o test_matrix $(TESTDIR)/test_matrix.cpp

.PHONY: run-test
run-test: test_matrix
	@./test_matrix

.PHONY: clean
clean:
	rm -rf test_matrix
