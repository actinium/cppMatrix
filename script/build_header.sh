#!/bin/bash

filename=$1
srcdir="src"

function clear_file {
  echo -n "" > $filename
}

function add_top_header_guard {
  echo "#ifndef ACTINIUM_MAT_MATRIX_H" >> $filename
  echo "#define ACTINIUM_MAT_MATRIX_H" >> $filename
  echo "" >> $filename
}

function add_bottom_header_guard {
  echo "#endif" >> $filename
}

function append_file {
  echo "//==============================================================================" >> $filename
  echo "//" >> $filename
  echo -n "// " >> $filename
  echo $1 >> $filename
  echo "//" >> $filename
  echo "//==============================================================================" >> $filename
  echo "" >> $filename
  cat $srcdir/$1 >> $filename
  echo "" >> $filename
}

echo "Generating Header File."

clear_file
add_top_header_guard
append_file matrix.h
append_file matrix_constructors_impl.h
append_file matrix_assignment_impl.h
append_file matrix_access_impl.h
append_file matrix_math_impl.h
append_file matrix_modifiers_impl.h
append_file matrix_iterators_impl.h
append_file matrix_comparison_impl.h
append_file matrix_helper_functions_impl.h
add_bottom_header_guard
