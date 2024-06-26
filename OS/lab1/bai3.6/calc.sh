#!/usr/bin/bash

signal=0 
res=0	 


declare -a hist=(
[0]="EMPTY"
[1]="EMPTY"
[2]="EMPTY"
[3]="EMPTY"
[4]="EMPTY"
)
idx=0 

while [[ $signal == 0 ]] 
do

	read -p ">> " num1 operator num2

	ch=$operator
	

	if [[ $operator != '+' ]] && [[ $operator != '-' ]] && [[ $operator != '*' ]] && [[ $operator != '/' ]] && [[ $operator != '%' ]] && [[ $operator != '' ]]; then
		echo "SYNTAX ERROR"
		continue
	

	elif [[ $num2 == 0 && $operator == '/' ]]; then 
		echo "MATH ERROR"
		continue
		

	elif [[ "$num1" == "HIST" ]]; then printf "%s\n" "${hist[@]}"
	

	elif [[ "$num1" == "EXIT" ]]; then break	
	elif [[ $num1 != "ANS" ]];
	

	then
		if [[ $ch == '+' ]]; then   res=$((num1+num2|bc))
		elif [[ $ch == '-' ]]; then res=$((num1-num2|bc))
		elif [[ $ch == '/' ]]; then res="scale=2; $num1/$num2"
		elif [[ $ch == '%' ]]; then res=$((num1%num2|bc))
		else                        res=$((num1*num2|bc))
		fi
		echo "$res" > ans.log.txt
	

	elif [[ $num1 == "ANS" ]];
	then
		filePath="./ans.log.txt"
		res=$(cat "$filePath")
		if [[ $ch == '+' ]]; then   res=$((res+num2|bc))
		elif [[ $ch == '-' ]]; then res=$((res-num2|bc))
		elif [[ $ch == '/' ]]; then res="scale=2; $res/$num2"
		elif [[ $ch == '%' ]]; then res=$((res%num2|bc))
		else                        res=$((res*num2|bc))
		fi
		echo "$res" > ans.log.txt
	fi
	

	if [[ "$num1" != HIST ]]; 
	then
		str1="$num1 "
		str2="$operator "
		str3="$num2"
		str4=" = "
		str5=$(echo "$res" |bc)
		hist[idx]=$str1$str2$str3$str4$str5
		idx=$((idx+1))
		if [[ $idx == 5 ]]; then idx=0
		fi
	fi
	

	if [[ "$num1" != HIST ]]; then echo "$res"|bc
	fi
	

	read cmd

done
