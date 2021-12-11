#!/bin/bash

working_folder=${PWD##*/}

problemname=$1
filename=${2:-${problemname}.cpp}
contestname=${3:-${working_folder}}
taskname=${4:-${contestname}}


sample_dir=sample_${problemname}
if [[ ! -e ${sample_dir} ]]; then
    oj dl -d ${sample_dir} "https://atcoder.jp/contests/${contestname}/tasks/${taskname}_${problemname}"
fi

fext="${filename##*.}"

if [ ${fext} = "cpp" ] ; then
    echo g ./${filename}
    g++-11 -O2 -std=gnu++17 -Wall -Wextra -DDEBUG ./${filename}
    oj t -d ${sample_dir} -i -N
elif [ ${fext} = "py" ] ; then
    echo python3 ${filename}
    oj t -d ${sample_dir} -c "python3 ${filename}" -i -N
elif [ ${fext} = "jl" ] ; then
    echo julia ${filename}
    oj t -d ${sample_dir} -c "julia ${filename}" -i -N
else
    echo "拡張子が正しくありません"
fi

rm -f a.out
# rm -rf ${sample_dir}