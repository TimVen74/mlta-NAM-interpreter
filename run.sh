#!/usr/bin/env bash

rm -fr build

cmake -B build
cmake --build build

cp "$1" build/input.txt
cp "$2" build/rules.txt

cd build
./main
cp output.txt ../src/output.txt
