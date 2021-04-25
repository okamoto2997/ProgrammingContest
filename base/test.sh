#/bin/sh

DIR=./
EXE=Main

cd ${DIR}

if [ ! -e "${EXE}" ]; then
  make ${EXE}
fi

find in -type f | while read input; do
  output=`basename ${input} .in`.out
  echo "test case: ${input}"
  ./${EXE} < ${input} | tee out/${output}
done