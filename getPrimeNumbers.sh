#!/bin/bash
echo "Enter the upper limit:"
read num
i=1
flag=0
while [ "$i" -le $num ]
  do
    j=2
    while [ "$j" -le $(($i / 2)) ]
    do
      case $(( $i % $j)) in
      0)flag=1;;
      esac
      j=$((j + 1))
    done
      case $flag in
      0)echo $i;;
      esac
      flag=0
      i=$((i + 1))
done