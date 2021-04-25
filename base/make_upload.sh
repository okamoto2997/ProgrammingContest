#!/bin/sh

if [ -z "$1" ]; then
  echo "Usage: $0 main_source"
  exit 1
fi

SOURCE=$1
DIR=`dirname $1`
SYSTEM_H=`mktemp make_upload.system.h.XXXXXX`
CONTENT=`mktemp make_upload.content.XXXXXX`
trap 'rm -f ${SYSTEM_H} ${CONTENT}' EXIT

sed -n "/^#include *<.*>/p" < ${SOURCE} > ${SYSTEM_H}
sed "/^#include *<.*>/d" < ${SOURCE} > ${CONTENT}

g++ -E -x c++ -I${DIR} -I${DIR}/../ -DNDEBUG ${CONTENT} | sed "/^#/d" | sed "/^ *$/d" >> ${SYSTEM_H}

mv ${SYSTEM_H} ${DIR}/upload.cpp