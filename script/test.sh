#/bin/sh

if [ -z "$1" ]; then
  echo "Usage: $0 path-to-executable"
  exit 1
fi


DIR=`dirname $1`/
EXE=`basename $1`

cd ${DIR}

if [ ! -e "${EXE}" ]; then
  make ${EXE}
fi

find in -type f | while read input; do
  output=`basename ${input} .in`.out
  echo "test case: ${input}"
  ./${EXE} < ${input} | tee out/${output}
done