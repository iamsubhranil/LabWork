#!/bin/bash

echo -e "Enter the no of terms : \c"
read n
a=0
b=1
if [ $n -eq 1 ]; then
	echo $a
elif [ $n -eq 2 ]; then
	echo $a $b
else
	echo -e "$a $b \c"
	i=1
	while [ $i -le `expr $n - 2` ]; do
		c=`expr $a + $b`
		echo -e "$c \c"
		a=$b
		b=$c
		i=`expr $i + 1`
	done
	echo
fi
