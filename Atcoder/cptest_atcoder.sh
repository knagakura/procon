#!/bin/bash

contestname=$1
problemname=$2
filename=${3:-${problemname}.cpp}
taskname=${4:-${contestname}}
oj dl "https://atcoder.jp/contests/${contestname}/tasks/${taskname}_${problemname}"
fext="${filename##*.}"

if [ ${fext} = "cpp" ] ; then
    echo g ./${filename}
    g++-9 -O2 -std=gnu++14 -Wall -Wextra -Wshadow ./${filename}
    oj t
elif [ ${fext} = "py" ] ; then
    echo python3 ${filename}
    oj t -c "python3 ${filename}"
elif [ ${fext} = "jl" ] ; then
    echo julia ${filename}
    oj t -c "julia ${filename}"
else
    echo "拡張子が正しくありません"
fi



rm -f a.out
rm -rf test