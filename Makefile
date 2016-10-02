CXX=clang++
CXXFLAGS= -I$(INCDIR) -Wall -std=c++11

INCDIR=include
TESTDIR=test

_INCLUDES= matrix.h \
           matrix_constructors_impl.h \
           matrix_assignment_impl.h \
           matrix_access_impl.h \
           matrix_math_impl.h \
           matrix_modifires_impl.h \
           matrix_comparison_impl.h \
           matrix_helper_functions_impl.h

INCLUDES=$(patsubst %,$(INCDIR)/%,$(_INCLUDES))

_TESTFILES= test_matrix.cpp \
						test_matrix_constructors.cpp

TESTFILES=$(patsubst %,$(TESTDIR)/%,$(_TESTFILES))

test_matrix:$(TESTFILES) $(INCLUDES)
	$(CXX) $(CXXFLAGS) -o test_matrix $(TESTFILES)

.PHONY: run-test
run-test: test_matrix
	@./test_matrix

.PHONY: clean
clean:
	rm -rf test_matrix
