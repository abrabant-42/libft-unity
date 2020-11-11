#!/bin/bash

PART1=false
PART2=false
FULL=false
RE=false

if [ $# -eq 0 ]; then
	disp_help
	exit 0
fi

while [ $# -gt 0 ]
do
	key=$1
	case $key in
		h|help)
		disp_help
		exit 0
		;;
		full)
		FULL=true
		shift
		;;
		p1|part1)
		PART1=true
		shift
		;;
		p2|part2)
		PART2=true
		shift
		;;
		b|bonus)
		BONUS=true
		shift
		;;
		--re)
		RE=true
		shift
		;;
		ft_*)
		FUNCS+=("$1")
		shift
		;;
		*)
		echo -e "\033[0;31mUnknown option \033[0m\"$1\" \033[0;31mAborted.\033[0m"
		exit 1
		;;
	esac
done


