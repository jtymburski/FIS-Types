#!/bin/bash

# ==============================================================================
# Opens a docker hosted terminal with all the required libraries to
# build with the internal Makefile.
#
# It expects the first parameter of the script to be Makefile target.
# ==============================================================================

if [ -z "$1" ]; then
  echo "First parameter must be a Makefile target"
  exit 1
fi

docker run -v /$(pwd):/mnt/BuildProject --rm jtymburski/sdl2-cross-make \
    sh -c "cd /mnt/BuildProject && make -j4 $1"
