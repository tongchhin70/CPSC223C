#!/bin/bash

#Author: Tong Chhin
#Author email: tongchhin@csu.fullerton.edu

#Program name: linesort.c


echo "Remove un-needed files, if any exist."
rm *.o
rm *.out

echo "Compile the C main function linesort according to C standard of year 2020"
gcc -c -Wall -std=c2x -o linesort.o -m64 -no-pie -fno-pie linesort.c


if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

echo "Link object files"
gcc -m64 -std=c2x linesort.o  -fno-pie -no-pie -o runprogram.out

if [ $? -ne 0 ]; then
    echo "Linking failed."
    exit 2
fi

echo "Run the program \"Text file I/O\""
./runprogram.out

if [ $? -ne 0 ]; then
    echo "Program execution failed."
    exit 3
fi

echo "The bash file has terminated."
