#!/bin/sh
case $2 in
-)
yr=2014
case $1 in
jan*|Jan*) k=1 ;;
feb*|Feb*) k=2 ;;
mar*|Mar*) k=3 ;;
apr*|Apr*) k=4 ;;
may*|May*) k=5 ;;
jun*|Jun*) k=6 ;;
jul*|Jul*) k=7 ;;
aug*|Aug*) k=8 ;;
sep*|Sep*) k=9 ;;
oct*|Oct*) k=10 ;;
nov*|Nov*) k=11 ;;
dec*|Dec*) k=12 ;;
[1-9]|10|11|12) ;;
esac

yr=2014
case $3 in
jan*|Jan*) l=1 ;;
feb*|Feb*) l=2 ;;
mar*|Mar*) l=3 ;;
apr*|Apr*) l=4 ;;
may*|May*) l=5 ;;
jun*|Jun*) l=6 ;;
jul*|Jul*) l=7 ;;
aug*|Aug*) l=8 ;;
sep*|Sep*) l=9 ;;
oct*|Oct*) l=10 ;;
nov*|Nov*) l=11 ;;
dec*|Dec*) l=12 ;;
[1-9]|10|11|12) ;;
esac
echo $k
echo $l
while [ "$k" -le $l ]
do
	 y=2014
	 /usr/bin/cal $k $y
         k=$((k + 1))
done
exit ;;
*)
for i 
do
echo $i
m=$i
y=2014
case $m in
jan*|Jan*) m=1 ;;
feb*|Feb*) m=2 ;;
mar*|Mar*) m=3 ;;
apr*|Apr*) m=4 ;;
may*|May*) m=5 ;;
jun*|Jun*) m=6 ;;
jul*|Jul*) m=7 ;;
aug*|Aug*) m=8 ;;
sep*|Sep*) m=9 ;;
oct*|Oct*) m=10 ;;
nov*|Nov*) m=11 ;;
dec*|Dec*) m=12 ;;
[1-9]|10|11|12) ;;
*)   y=$m; m="" ;;
esac
/usr/bin/cal $m $y
done
esac 
