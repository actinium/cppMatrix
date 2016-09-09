CXX=clang++
CXXFLAGS= -I$(INCDIR) -Wall -std=c++11

INCDIR=include
TESTDIR=test

_INCLUDES= matrix.h \
           matrix.constructors.inc.h \
           matrix.assignment.inc.h \
           matrix.access.inc.h \
           matrix.modifires.inc.h \
           matrix.comparison.inc.h

INCLUDES=$(patsubst %,$(INCDIR)/%,$(_INCLUDES))

test_matrix:$(TESTDIR)/test_matrix.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) -o test_matrix $(TESTDIR)/test_matrix.cpp

.PHONY: run-test
run-test: test_matrix
	@./test_matrix

.PHONY: clean
clean:
	rm -rf test_matrix
