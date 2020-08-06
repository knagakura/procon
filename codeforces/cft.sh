#!/bin/bash

working_folder=${PWD##*/}

problemname="$1"
filename=${2:-${problemname}.cpp}
contestname=${3:-${working_folder}}

sample_dir=sample_${problemname}
if [[ ! -e ${sample_dir} ]]; then
    oj dl -d ${sample_dir} https://codeforces.com/contest/${contestname}/problem/${problemname}
fi

fext="${filename##*.}"

if [ ${fext} = "cpp" ] ; then
    echo g ./${filename}
    g++-9 -O2 -std=gnu++17 -Wall -Wextra -DDEBUG ./${filename}
    oj t -d ${sample_dir} -i
else
    echo "拡張子が正しくありません"
fi

rm -f a.out
