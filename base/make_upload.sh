#!/bin/sh

print_usage(){
  cat <<EOF
Usage: ${0} [source_code = "Main.cpp"]
  -h
    print this message and exit.
EOF
}

SOURCE="Main.cpp"

while [ -n "$*" ]; do
  OPT=$1
  case "$OPT" in
    "-h" )
      print_usage
      exit
      ;;
    * )
      SOURCE=$1
      ;;
  esac
  shift
done

echo "Target: ${SOURCE}"

DIR=`dirname $SOURCE`
DIR=`cd ${DIR}; pwd`

WORK=`mktemp -d tmp.upload.XXXXXX`
WORK=`cd ${WORK}; pwd`
FILE_LIST=${WORK}/file_list

g++ -MM -I. -std=gnu++17 -Wall -Wextra -O2 ${SOURCE} \
  | tr -d "\n" | tr -d '\\' | sed -e "s/[a-zA-Z.]\+://" > ${FILE_LIST}

cd ${WORK}

SYSTEM_H=`mktemp system_headers.XXXXXX`
trap 'rm -rf ${WORK} a.out' EXIT

for file in `cat ${FILE_LIST}`; do
  mkdir -p `dirname ${file}`
  sed -n "/^#include *<.*>/p" < ${DIR}/${file} >> ${SYSTEM_H}
  sed "/^#include *<.*>/d" < ${DIR}/${file} > ${file}
done

g++ -E -x c++ -I${DIR} -I${DIR}/../ -DNDEBUG ${SOURCE} | sed "/^#/d" | sed "/^ *$/d" >> ${SYSTEM_H}

mv ${SYSTEM_H} ${DIR}/upload.cpp

cd -
echo "compile test."

g++ -std=gnu++17 -Wall -Wextra -O2 -DONLINE_JUDGE -o ./a.out ./upload.cpp

echo "complete."

code ${DIR}/upload.cpp
