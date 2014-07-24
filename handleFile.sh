#!/bin/bash
#A file contains details of 10 students. Details include (Student Name, RollNo, Address, TotalMarks). 
#Field of each record can be delimited by space bar. Write a shell script which provide the following options
echo "Please select the option "
echo "
a) Sort the records in the order of student name
b) Sort the record in the order of Roll No
c) Sort the record in the order of Address
d) Sort the record in the order of Total Marks "
read ans
case $ans in
a) 
echo "Sorting in order of student name "
sort $1 -k1 | tail -n 2
sort $1 -k4 | head -n 2;;
b)
echo "Sorting in order of Roll no"
sort $1 -k2 | tail -n 2
sort $1 -k4 | head -n 2;;
c)
echo "Sorting in order of Address "
sort $1 -k3 | tail -n 2
sort $1 -k4 | head -n 2;;
d)
echo "Sorting in order of Total Marks "
sort $1 -k4 | tail -n 2
sort $1 -k4 | head -n 2;;
esac

#Search for a particular record based on the key value (rollno) entered by user.
echo "enter a roll no "
read roll
grep $roll $1


