#!/bin/sh

if [ -z "$1" ]; then
  echo "Usage: $0 Q-id"
  exit 1
fi

QID=$1

if [ ! -e "$QID" ]; then
  cp -rn template/ ${QID}
  echo "${QID} is prepared."
  echo "Good luck!"
else
  echo "${QID} already exists."
fi