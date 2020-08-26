#!/bin/bash
#g++ -o factory --std=c++14 -pg -I. main.cpp factory.cpp
mkdir -p libs
set -v

# Compile Standard Solvers library
g++ -c CSolver/CSolver.cpp CEulerSolver/CEulerSolver.cpp -I. -fPIC -Wall -Werror
g++ -shared -o libs/libCSolvers.so CSolver.o CEulerSolver.o

# Compile Custom Solvers library
g++ -c CCustomSolver/CCustomSolver.cpp -I. -fPIC -Wall -Werror
g++ -shared -o libs/libCCustomSolvers.so CCustomSolver.o

# Link main program with standard solvers only
g++ -o main main.cpp -Wl,-rpath=./libs -L./libs -ldl -lCSolvers
