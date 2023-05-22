#!/bin/bash

# Compile the C++ program
g++ -o mtr mtr.cpp

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful."

    # Run the program
    ./mtr
else
    echo "Compilation failed. Please check for errors."
fi
