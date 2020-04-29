#!/bin/bash
working_folder=${PWD##*/}
problemname=$1
filename=${2:-${problemname}.cpp}
contestname=${3:-${working_folder}}
taskname=${4:-${contestname}}

fext="${filename##*.}"


#language=${3003}
#if [ ${fext} = "cpp" ] ; then
#    language=3003
#elif [ ${fext} = "jl" ] ; then
#    language=3018
#elif [ ${fext} = "py" ] ; then
#    echo -n which language, py, pypy?:\ ; read
#    if [ $REPLY = "pypy" ] ; then
#        language=3510
#    elif [ $REPLY = "py" ] ; then
#        language=3023
#    else
#        echo 入力が間違っています
##        exit
#  fi
#fi
oj s "https://atcoder.jp/contests/${contestname}/tasks/${taskname}_${problemname}" ${filename}
#oj s -l ${language} "https://atcoder.jp/contests/${contestname}/tasks/${taskname}_${problemname}" ${filename}
