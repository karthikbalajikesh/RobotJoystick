#!/bin/bash

echo "Building Client"

mkdir build && cd build
cmake ..
make
