#!/bin/bash
echo "Enter test case "
read alpha
case $alpha in
[0-9]) echo "number"		;;
[a-zA-Z]) echo "alphabet"	;;
esac
