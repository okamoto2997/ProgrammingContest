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
SYSTEM_H=`mktemp make_upload.system.h.XXXXXX`
CONTENT=`mktemp make_upload.content.XXXXXX`
trap 'rm -f ${SYSTEM_H} ${CONTENT}' EXIT

sed -n "/^#include *<.*>/p" < ${SOURCE} > ${SYSTEM_H}
sed "/^#include *<.*>/d" < ${SOURCE} > ${CONTENT}

g++ -E -x c++ -I${DIR} -I${DIR}/../ -DNDEBUG ${CONTENT} | sed "/^#/d" | sed "/^ *$/d" >> ${SYSTEM_H}

mv ${SYSTEM_H} ${DIR}/upload.cpp
code ${DIR}/upload.cpp
