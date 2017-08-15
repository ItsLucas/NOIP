#!/bin/bash
cd $1
c++ $1.cpp
for((i=$2;i<=$3;++i))
do
	cp $1$i.in $1.in
	./a.out
	diff -s -w $1$i.out $1.out
	rm $1.out
	rm $1.in
done

