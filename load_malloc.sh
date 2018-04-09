#!/bin/sh

make re
echo ""
arg=$1
make clean
LD_PRELOAD="./libmy_malloc.so" $arg
