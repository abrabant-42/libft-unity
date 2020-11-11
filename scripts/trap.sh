#!/bin/bash

function	interrupt()
{
	echo -e "\n\033[0;31mUnexpected test interruption.\033[0m Cleaned up."
	rm -rf .gnltest
	exit 1
}

trap interrupt SIGINT
