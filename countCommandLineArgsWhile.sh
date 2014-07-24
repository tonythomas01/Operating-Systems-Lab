#!/bin/bash
args=0
while [ -n "$1" ]
do 
  args=$((args+1))
  shift
done
echo "The number of command line args is "$args