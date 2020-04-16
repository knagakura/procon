#!/bin/bash

working_folder=${PWD##*/}

problemname="$1"
filename=${2:-${problemname}.cpp}
contestname=${3:-${working_folder}}
oj dl https://codeforces.com/contest/${contestname}/problem/${problemname}

fext="${filename##*.}"

if [ ${fext} = "cpp" ] ; then
    echo g ./${filename}
    g++-9 -O2 -std=gnu++17 -Wall -Wextra ./${filename}
    oj t
else
    echo "拡張子が正しくありません"
fi



rm -f a.out
rm -rf test