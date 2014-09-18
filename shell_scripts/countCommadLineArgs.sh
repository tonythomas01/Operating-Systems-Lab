#!/bin/sh
count=0
for i in $*
  do
  count=$((i+1))
  done
echo $count
  