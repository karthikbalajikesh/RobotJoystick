#!/bin/bash

echo "Building Server"

mkdir build && cd build
cmake ..
make
