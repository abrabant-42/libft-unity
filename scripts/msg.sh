#!/bin/bash

function disp_help()
{
	printf "\n\033[0;34mlibft-unity \033[0;32m$VER \033[0mby \033[0;33m$AUTHOR\033[0m\n\n"
	printf "%-15s Displays this help menu.\n" "help | h"
	printf "%-15s Starts the test runner for all the parts together.\n" "full"
	printf "%-15s Starts the test runner for the libft part1.\n" "part1 | p1"
	printf "%-15s Starts the test runner for the libft part2.\n" "part2 | p2"
	printf "%-15s Starts the test runner for the libft bonus part.\n" "bonus | b"
	printf "%-15s Starts the test runner for a specific function.\n" "ft_*"
	printf "%-15s make re before making the test binary.\n" "--re"
	printf ""
}

function fatal_error() {
	printf "[\033[0;31mFATAL\033[0m] $1\n"
	exit $2
}
