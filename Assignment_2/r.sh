#!/bin/bash

#Author: Tong Chhin
#Author email: tongchhin@csu.fullerton.edu

#Program name: linesort.c


echo "Remove un-needed files, if any exist."
rm -f *.o
rm -f *.out

<<<<<<< HEAD
echo "Compile the C main function chemistry.c according to C standard of year 2020"
gcc -c -Wall -std=c2x -o linesort.o -m64 -no-pie -fno-pie linesort.c
=======
echo "Compiling the C program datastring.c according to C standard of year 2020"
gcc -c -Wall -std=c2x -o datastring.o -m64 -no-pie -fno-pie datastring.c
>>>>>>> 9cc23dc7e0151bcea53c2799897716757c2d9ecf


if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

echo "Link object files"
<<<<<<< HEAD
gcc -m64 -std=c2x linesort.o -fno-pie -no-pie -o runprogram.out
=======
gcc -m64 datastring.o -fno-pie -no-pie -o runprogram.out
>>>>>>> 9cc23dc7e0151bcea53c2799897716757c2d9ecf

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
