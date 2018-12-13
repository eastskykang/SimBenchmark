#!/usr/bin/env bash

set -e

echo "SimBenchmark Build"
echo ""
echo "==========================================================================="
echo "Install dependencies..."
echo ""

# install apt packages
echo "Install apt packages..."

sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt update

sudo apt install -y -qq g++-7
sudo apt install -y -qq \
libeigen3-dev \
libboost-all-dev \
libglew-dev \
libglm-dev \
libsdl2-dev \
libassimp-dev \
libsoil-dev \
libsdl2-ttf-dev \
liburdfdom-dev \
libgtest-dev \
google-perftools \
libgoogle-perftools-dev \
libpng-dev

# create build directory
echo "Creating build directory..."
rm -rf build
mkdir build && cd build

# cmake
echo "Configuring dependencies by cmake externalproject..."
cmake ../

# build
echo "Building dependencies (it takes minutes)..."
make ex_all -j4

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