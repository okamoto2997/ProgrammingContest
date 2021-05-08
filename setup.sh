#!/bin/sh

if [ -z "$1" ]; then
  echo "Usage: $0 dir"
  exit 1
fi

ROOT=`dirname $0`
ROOT=`cd ${ROOT}; pwd`

BASE=${ROOT}/base

echo "create and move: $1"
mkdir -p $1
cd $1

RBASE=`realpath --relative-to=. ${ROOT}`
ln -snf ${RBASE}/base/Makefile .
ln -snf ${RBASE}/base/lib .
ln -snf ${RBASE}/base/make_upload.sh .
ln -snf ${RBASE}/base/test.sh .

mkdir -p template
cd template

RBASE=`realpath --relative-to=. ${BASE}/template`
ln -snf ${RBASE}/Makefile .
cp ${RBASE}/Main.cpp .

mkdir -p in
touch in/1.in
mkdir -p out
echo "*
!.gitignore" > out/.gitignore

echo "completed. Good luck!"