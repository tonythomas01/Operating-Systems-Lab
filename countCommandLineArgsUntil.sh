#!/bin/bash
args=0
until [ -z "$1" ]
do	
    args=$((args+1))
    shift
done
echo "number of args is "$args