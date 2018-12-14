#!/usr/bin/env bash
set -ex

# create build directory
echo "Creating build directory..."
rm -rf build
mkdir build && cd build

# cmake
echo "Configuring dependencies by cmake externalproject..."
cmake -DCMAKE_BUILD_TYPE=Release \
    -DMUJOCO=OFF \
    -DRAISIM=OFF \
    ../

# build
echo "Building dependencies (it takes minutes)..."
make ex_all

echo "==========================================================================="
echo "Install SimBenchmark..."
echo ""

# cmake
echo "Configuring SimBenchmark by cmake..."
cmake ../

# build
echo "Building SimBenchmark..."
make -j4

echo "==========================================================================="
echo "SimBenchmark build done!"
echo ""