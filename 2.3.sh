#!/bin/bash
echo "ENTER THREE NUMBERS"
read a b c
if [ $a -gt $b ] && [ $a -gt $c ]
then
echo "$a is greater"
elif [ $b -gt $c ]
then
echo "$b is greater"
else
echo "$c is greater"
fi

=========================
ENTER THREE NUMBERS
5 3 2
5 is greater
=========================

2: Factorial of a Given Number

#!/bin/bash
echo "ENTER THE NUMBER:"
read n
fact=1
while [ $n -gt 1 ]
do
fact=$((fact * n))
n=$((n - 1))
done
echo "FACTORIAL OF THE GIVEN NUMBER IS $fact"

===============================
ENTER THE NUMBER:
17
FACTORIAL OF THE GIVEN NUMBER IS 355687428096000
================================

3: Sum of Odd Numbers up to N

#!/bin/bash
echo "ENTER THE RANGE:"
read n
x=1
sum=0
while [ $x -le $n ]
do
sum=$((sum + x))
x=$((x + 2))
done
echo "SUM = $sum"

=====================
ENTER THE RANGE:
18
SUM = 81
===================

4: Generation of Fibonacci Numbers

#!/bin/bash
echo "ENTER THE LIMIT:"
read n
p=-1
q=1
i=1
while [ $i -le $n ]
do
r=$((p + q))
p=$q
q=$r
echo "$r"
i=$((i + 1))
done

=========================
ENTER THE LIMIT:
10
0
1
1
2
3
5
8
13
21
34
==========================

5: Arithmetic Calculator

#!/bin/bash
echo "ENTER THE VALUE OF A:"
read a
echo "ENTER THE VALUE OF B:"
read b
echo "ENTER THE OPTION TO PERFORM"
echo "1. ADDITION"
echo "2. SUBTRACTION"
echo "3. MULTIPLICATION"
echo "4. DIVISION"
read op
case "$op" in
1) echo "Result = $((a + b))" ;;
2) echo "Result = $((a - b))" ;;
3) echo "Result = $((a * b))" ;;
4) echo "Result = $((a / b))" ;;
*) echo "Invalid Option" ;;
esac


=================
ENTER THE VALUE OF A:
10
ENTER THE VALUE OF B:
5
ENTER THE OPTION TO PERFORM
1. ADDITION
2. SUBTRACTION
3. MULTIPLICATION
4. DIVISION
1
Result = 15
======================

6: Largest Digit of a Number

#!/bin/bash
echo "ENTER THE NUMBER"
read a
max=0
while [ $a -gt 0 ]
do
r=$((a % 10))
if [ $r -gt $max ]
then
max=$r
fi
a=$((a / 10))
done
echo "THE LARGEST DIGIT OF THE NUMBER: $max"

========================
ENTER THE NUMBER
5834
THE LARGEST DIGIT OF THE NUMBER: 8
============================

7: Palindrome String Check

#!/bin/bash
echo "ENTER THE STRING TO CHECK PALINDROME"
read str
len=$(echo -n "$str" | wc -c)
i=1
j=$((len / 2))
while [ $i -le $j ]
do
k=$(echo "$str" | cut -c $i)
l=$(echo "$str" | cut -c $len)
if [ "$k" != "$l" ]
then
echo "$str is not a palindrome"
exit
fi
i=$((i + 1))
len=$((len - 1))
done
echo "$str is a palindrome"

=========================
ENTER THE STRING TO CHECK PALINDROME
madam
madam is a palindrome
==========================

8: Reverse of a Given Number

#!/bin/bash
echo "ENTER THE NUMBER"
read n
rnum=0
while [ $n -ne 0 ]
do
remainder=$((n % 10))
rnum=$((rnum * 10 + remainder))
n=$((n / 10))
done
echo "REVERSE OF THE NUMBER IS $rnum"  

==============================
ENTER THE NUMBER
5387
REVERSE OF THE NUMBER IS 7835
==============================
