#!/bin/bash

if [[ $TRAVIS_OS_NAME == "osx" ]] ; then
  brew install --force qt@5.7
  brew install protobuf
fi
