#!/bin/sh

print_usage(){
  cat <<EOF
Usage: ${0} [source_code]
  -d dir
    directorty contining executable. if -d is not set, obtained from -e
  -e executable
    executable to test. if -e is not set, "-e ./Main" is assumed.
  -h
    print this message and exit.
EOF
}

while [ -n "$*" ]; do
  OPT=$1
  case "$OPT" in
    "-h" )
      print_usage
      exit
      ;;
  esac
  shift
done

SOURCE="Main.cpp"

if [ -n "$1" ]; then
  SOURCE=$1
fi

DIR=`dirname $SOURCE`
SYSTEM_H=`mktemp make_upload.system.h.XXXXXX`
CONTENT=`mktemp make_upload.content.XXXXXX`
trap 'rm -f ${SYSTEM_H} ${CONTENT}' EXIT

sed -n "/^#include *<.*>/p" < ${SOURCE} > ${SYSTEM_H}
sed "/^#include *<.*>/d" < ${SOURCE} > ${CONTENT}

g++ -E -x c++ -I${DIR} -I${DIR}/../ -DNDEBUG ${CONTENT} | sed "/^#/d" | sed "/^ *$/d" >> ${SYSTEM_H}

mv ${SYSTEM_H} ${DIR}/upload.cpp
code ${DIR}/upload.cpp
