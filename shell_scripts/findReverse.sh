#!/bin/bash
echo "Enter a number "
read num
rev=""
rev=0
while [ $num -gt 0 ]
do
  rev=$((( rev * 10 )  + $(( $num % 10 )) ))
  num=$(( $num / 10 ))
done
echo "The reverse is:"$rev