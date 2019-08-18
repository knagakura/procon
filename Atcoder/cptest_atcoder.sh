#!/bin/bash
problemname=$1
oj dl "https://atcoder.jp/contests/${problemname:0:6}/tasks/$1"
echo ///////////////
echo //     g ./${problemname:7:8}.cpp      //
echo ///////////////
g++-8 -O2 -std=gnu++14 -Wall -Wextra -Wshadow ./${problemname:7:8}.cpp

oj test
rm -f a.out
rm -rf test 
