CXX=clang++
CXXFLAGS= -I$(INCDIR) -Wall -std=c++11

DIR_GUARD=@mkdir -p $(@D)

INCDIR=src
TESTDIR=test
OBJDIR=obj

_INCLUDES= matrix.h \
           matrix_constructors_impl.h \
           matrix_assignment_impl.h \
           matrix_access_impl.h \
           matrix_math_impl.h \
           matrix_modifiers_impl.h \
           matrix_iterators_impl.h \
           matrix_comparison_impl.h \
           matrix_helper_functions_impl.h

INCLUDES=$(patsubst %,$(INCDIR)/%,$(_INCLUDES))

_OBJECTS= test_main.o \
          test_matrix_constructors.o \
          test_matrix_access.o \
          test_matrix_modifiers.o \
          test_matrix_math.o \
          test_matrix_comparison.o

OBJECTS=$(patsubst %,$(OBJDIR)/%,$(_OBJECTS))

test_matrix: $(OBJECTS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

$(OBJDIR)/test_main.o: $(TESTDIR)/test_main.cpp
	$(DIR_GUARD)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(OBJDIR)/%.o: $(TESTDIR)/%.cpp $(INCLUDES)
	$(DIR_GUARD)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: run-test
run-test: test_matrix
	@./test_matrix

.PHONY: clean
clean:
	rm -rf test_matrix $(OBJDIR)
