#!/bin/bash
#echo "Numarul parametrilor e $#"
PROGRAM_NAME=$1
PREFIX=${PROGRAM_NAME%.cc}
#echo "executabilul se numeste $PREFIX"

# -g (debugger) i executem amb valgrind
g++ -Wall -O2 --std=c++11 $PROGRAM_NAME -o $PREFIX
