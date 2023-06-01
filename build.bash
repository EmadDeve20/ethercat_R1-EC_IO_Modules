#!/bin/bash

git submodule init && git submodule update

if [ ! -d build ]
then
	mkdir build 
fi

cd build
cmake ../ethercat_R1-EC_IO_Modules/ . && make
