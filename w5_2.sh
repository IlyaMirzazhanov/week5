#!/bin/bash 
                                                 
if test ! -f nums
then
    echo 0 > numbers_test
fi

if ln numbers_test numbers_test.lock
	then                                                                    
	for i in `seq 1 100`;
	do
		LASTNUM=`tail -1 numbers_test`
		LASTNUM=$((LASTNUMBER+1))

		echo $LASTNUMBER >> nums
	done

	rm nums.lock
fi