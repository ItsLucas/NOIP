#!/bin/bash
for((i=1;i<=15;i++))
do
	diff cardgame/$i.out ./a.out > cardgame/$i.in
done
