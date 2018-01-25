#!/bin/bash

if [[ $TRAVIS_OS_NAME == "osx" ]] ; then
  brew install ccache
  export PATH="/usr/local/opt/ccache/libexec:$PATH"
  brew install --force qt@5.7
  brew install protobuf
fi
