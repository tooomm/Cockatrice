#!/bin/bash

if [[ $TRAVIS_OS_NAME == "osx" ]] ; then
  brew install ccache
  export PATH="/usr/local/opt/ccache/libexec:$PATH"
fi
