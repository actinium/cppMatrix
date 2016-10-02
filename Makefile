CXX=clang++
CXXFLAGS= -I$(INCDIR) -Wall -std=c++11

DIR_GUARD=@mkdir -p $(@D)

INCDIR=include
TESTDIR=test
OBJDIR=obj

_INCLUDES= matrix.h \
           matrix_constructors_impl.h \
           matrix_assignment_impl.h \
           matrix_access_impl.h \
           matrix_math_impl.h \
           matrix_modifires_impl.h \
           matrix_comparison_impl.h \
           matrix_helper_functions_impl.h

INCLUDES=$(patsubst %,$(INCDIR)/%,$(_INCLUDES))

_OBJECTS= test_matrix.o \
          test_matrix_constructors.o

OBJECTS=$(patsubst %,$(OBJDIR)/%,$(_OBJECTS))

test_matrix: $(OBJECTS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

$(OBJDIR)/%.o: $(TESTDIR)/%.cpp $(INCLUDES)
	$(DIR_GUARD)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: run-test
run-test: test_matrix
	@./test_matrix

.PHONY: clean
clean:
	rm -rf test_matrix $(OBJDIR)
