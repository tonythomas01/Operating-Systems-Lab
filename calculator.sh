#!/bin/bash
echo "First Opearnd "
read x
echo "Operator "
read operator
echo "Third Opearnd "
read y
case $operator in
+) echo "add"
echo $(( x + y ))	;;
-) echo "sub"
echo $(( x - y )) 	;;
\*) echo "mult"
echo $(( x * y ))	;;
/) echo "div"
echo $(( x / y ))	;;
*) echo "wrong input "	;;
esac