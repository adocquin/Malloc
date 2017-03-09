#!/bin/sh

make re
gcc main.c
echo ""
arg=$1
LD_PRELOAD="./libmy_malloc.so" $arg
