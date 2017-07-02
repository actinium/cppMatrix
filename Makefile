CXX=clang++
CXXFLAGS= -I$(INCDIR) -Wall -std=c++11

DIR_GUARD=@mkdir -p $(@D)

SRCDIR=src
INCDIR=single_include
TESTDIR=test
OBJDIR=obj

MATRIX_HEADER=$(INCDIR)/matrix.h

_SOURCES= matrix.h \
          matrix_constructors_impl.h \
          matrix_assignment_impl.h \
          matrix_access_impl.h \
          matrix_math_impl.h \
          matrix_modifiers_impl.h \
          matrix_iterators_impl.h \
          matrix_comparison_impl.h \
          matrix_helper_functions_impl.h\
          matrix_swap_impl.h\
					matrix_output_impl.h

SOURCES=$(patsubst %,$(SRCDIR)/%,$(_SOURCES))

_OBJECTS= test_main.o \
          test_matrix_constructors.o \
          test_matrix_access.o \
          test_matrix_iterators.o \
          test_matrix_modifiers.o \
          test_matrix_math.o \
          test_matrix_comparison.o\
          test_matrix_swap.o\
          test_matrix_output.o

OBJECTS=$(patsubst %,$(OBJDIR)/%,$(_OBJECTS))

test_matrix: $(OBJECTS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

$(MATRIX_HEADER): scripts/build_header.sh $(SOURCES)
	$(DIR_GUARD)
	@./scripts/build_header.sh $(MATRIX_HEADER)

$(OBJDIR)/test_main.o: $(TESTDIR)/test_main.cpp
	$(DIR_GUARD)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(OBJDIR)/%.o: $(TESTDIR)/%.cpp $(MATRIX_HEADER)
	$(DIR_GUARD)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: run-test
run-test: test_matrix
	@./test_matrix

.PHONY: clean
clean:
	rm -rf test_matrix $(OBJDIR)
