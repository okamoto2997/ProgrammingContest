#/bin/sh

print_usage(){
  cat <<EOF
Usage: ${0} [-d dir] [-e executable] [-h]
  -d dir
    directorty contining executable. if -d is not set, obtained from -e
  -e executable
    executable to test. if -e is not set, "-e ./Main" is assumed.
  -h
    print this message and exit.
EOF
}

DIR=
EXE=./Main

while [ -n "$*" ]; do
  OPT=$1
  case "$OPT" in
    "-d" )
      DIR=$2
      shift
      ;;
    "-e" )
      EXE=$2
      shift
      ;;
    "-h" )
      print_usage
      exit
      ;;
  esac
  shift
done

if [ -z "$DIR" ]; then
  DIR=`dirname ${EXE}`
fi

EXE=`basename ${DIR}/${EXE}`

cd ${DIR}

if [ ! -e "${EXE}" ]; then
  make ${EXE}
fi

find in -type f | sort | while read input; do
  output=`basename ${input} .in`.out
  echo "test case: ${input}"
  ./${EXE} < ${input} > out/${output}
  cat out/${output}
done