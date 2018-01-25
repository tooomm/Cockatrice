#!/bin/bash

set -e

./servatrice/check_schema_version.sh

mkdir -p build
cd build
prefix=""
if [[ $TRAVIS_OS_NAME == "osx" ]]; then
  prefix="-DCMAKE_PREFIX_PATH=$(echo /usr/local/opt/qt*/)"
fi
if [[ $TRAVIS_OS_NAME == "linux" ]]; then
  export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$(echo /opt/qt5*/lib/)"
  prefix="-DCMAKE_PREFIX_PATH=$(echo /opt/qt5*/lib/cmake/)"
fi

if [[ $BUILDTYPE == "Debug" ]]; then
	cmake .. -DWITH_SERVER=1 -DTEST=1 -DCMAKE_BUILD_TYPE=$BUILDTYPE $prefix
	make -j2
	make test
fi
if [[ $BUILDTYPE == "Release" ]]; then
	cmake .. -DWITH_SERVER=1 -DCMAKE_BUILD_TYPE=$BUILDTYPE $prefix
	make package -j2
fi
