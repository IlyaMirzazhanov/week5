#!/bin/bash                     
                            
if [ ! -f numbers_test.txt ]; then
	echo 0 > numbers_test.txt
fi

cnt=0
while [ $cnt -lt 100 ]; do
	if ln numbers_test.txt numbers_test.lock ; then
		cnt=$(expr $cnt + 1)
		val=$(tail -1 numbers_test.txt)                     
		val=$(expr $val + 1)
		echo $val >> numbers_test.txt            
		rm numbers_test.lock
	fi                  
done                            