#!/bin/sh

if [ -z "$1" ]; then
  echo "Usage: $0 dir"
  exit 1
fi

ROOT=`dirname $0`
ROOT=`cd ${ROOT}/../; pwd`

BASE=${ROOT}/base

echo "create and move: $1"
mkdir -p $1
cd $1

RBASE=`realpath --relative-to=. ${ROOT}`
ln -snf ${RBASE}/base/Makefile .
ln -snf ${RBASE}/script .

mkdir -p template
cd template

RBASE=`realpath --relative-to=. ${BASE}/A`
ln -snf ${RBASE}/Makefile .
cp ${RBASE}/Main.cpp .

mkdir in
touch in/1.in
mkdir out
echo "*
!.gitignore" > out/.gitignore

cd ../

cp -r template A

echo "completed. Good luck!"