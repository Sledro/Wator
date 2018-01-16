#!/bin/bash
# chmod 755 ./profile.sh first to run this file via command line
# This file will clean, build and run the program and produce a valgrind profiling report
# on compleation the valgrind report can be viewed with kcachegrind GUI tool
# To install profiling tools:

# sudo apt-get update
# sudo apt install valgrind
# sudo apt install kcachegrind

# Remove the old .o files
make clean

# Build
make

# run the program with callgrind; generates a file callgrind.out.12345 that can be viewed with kcachegrind
valgrind --tool=callgrind ./main

# open profile.callgrind with kcachegrind
kcachegrind profile.callgrind
