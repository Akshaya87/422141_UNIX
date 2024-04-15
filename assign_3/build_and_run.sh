#!/bin/bash

# Compile source files into object files
gcc -c -fPIC push_pop.c NQueens.c

# Check if object files were created successfully
if [ $? -ne 0 ]; then
    echo "Error: Failed to compile source files into object files"
    exit 1
fi

# Create static library
ar rcs libFunctions.a push_pop.o NQueens.o

# Check if static library was created successfully
if [ $? -ne 0 ]; then
    echo "Error: Failed to create the static library"
    exit 1
fi

# Create dynamic library
gcc -shared -o libFunctions.so push_pop.o NQueens.o

# Check if dynamic library was created successfully
if [ $? -ne 0 ]; then
    echo "Error: Failed to create the dynamic library"
    exit 1
fi

# Set LD_LIBRARY_PATH to include current directory
export LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH

# Compile main program with static library
gcc main.c -L. -lFunctions -o main_static

# Check if main program with static library was compiled successfully
if [ $? -ne 0 ]; then
    echo "Error: Failed to compile the main program with static library"
    exit 1
fi