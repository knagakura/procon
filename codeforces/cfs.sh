#!/bin/bash
working_folder=${PWD##*/}
problemname=$1
filename=${2:-${problemname}.cpp}
contestname=${3:-${working_folder}}

fext="${filename##*.}"

oj s https://codeforces.com/contest/${contestname}/problem/${problemname} ${filename}
