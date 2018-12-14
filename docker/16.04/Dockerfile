FROM ubuntu:16.04

# apt update
RUN apt-get update -qq && apt-get -y -qq upgrade

# essentials
RUN apt-get install -y -qq build-essential git software-properties-common

# cmake
RUN apt-get install -y -qq cmake

# g++ 
RUN add-apt-repository ppa:ubuntu-toolchain-r/test && \
    apt-get update && \
    apt-get install -y -qq g++-7

# raicommon dependencies
RUN apt-get install -y -qq gnuplot5

# raigraphics dependencies
RUN apt-get install -y -qq \
    libeigen3-dev \
    libboost-all-dev \
    libglew-dev \
    libglm-dev \
    libsdl2-dev \
    libassimp-dev \
    libsoil-dev \
    libsdl2-ttf-dev \
    libsdl2-image-dev \
    ffmpeg \
    libpng-dev

# urdf-dom
RUN apt-get install -y -qq \
    liburdfdom-dev

# raisim dependencies
RUN apt-get install -y -qq \
    libgtest-dev \
    google-perftools \
    libgoogle-perftools-dev

# bullet install (for dart)
# NOTE this is only for 16.04 since apt in 16.04 doesnot support libbullet-dev 2.87
RUN cd /tmp/ && \
    git clone --single-branch --branch \
    release/2.87 \
    https://github.com/eastskykang/bullet3.git
RUN cd /tmp/bullet3/build && \
     cmake -DUSE_DOUBLE_PRECISION=ON \
    -DBUILD_SHARED_LIBS=ON \
    -DBULLET2_MULTITHREADING=OFF \
    -DBUILD_BULLET3=ON \
    -DBUILD_PYBULLET=OFF \
    -DBUILD_BULLET2_DEMOS=OFF \
    -DBUILD_EXTRAS=ON \
    -DBUILD_UNIT_TESTS=OFF \
    ../
RUN cd /tmp/bullet3/build && make install

# dart dependencies
RUN apt-get remove -y -qq libdart*
RUN apt-get install -y -qq \
    libassimp-dev \
    libccd-dev \
    libfcl-dev \
    libopenscenegraph-dev \
    libnlopt-dev \
    coinor-libipopt-dev \
    libode-dev \
    libflann-dev \
    liboctomap-dev \
    libtinyxml2-dev
