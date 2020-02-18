#!/bin/bash

contestname=$1
problemname=$2
filename=${3:-${problemname}.cpp}
taskname=${4:-${contestname}}
oj dl "https://atcoder.jp/contests/${contestname}/tasks/${taskname}_${problemname}"
echo g ./${filename}

g++-9 -O2 -std=gnu++14 -Wall -Wextra -Wshadow ./${filename}

oj t
rm -f a.out
rm -rf test
