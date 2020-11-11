#!/bin/bash

source scripts/setup.sh
source scripts/setup_env.sh
source scripts/trap.sh
source scripts/constants.sh
source scripts/msg.sh

#parse command line arguments
BONUS=0
PART1=0
PART2=0
RE=0
FUNCS=()

# Parse the command line arguments and do basic setup
source scripts/parse.sh

# Parses the libft pat
LIBFT_PATH=$(eval echo $(grep -i "path" libft_unity.config | cut -d= -f 2))

#Check if the path is correct
if [ ! -d "$LIBFT_PATH" ]; then
	fatal_error "\033[0;34m$LIBFT_PATH \033[0;31mcould not be found. Aborted.\033[0m" $EXIT_PATH_ERROR
fi

#Check if a Makefile is found
if [ ! -f "$LIBFT_PATH/Makefile" ] && [ ! -f "$LIBFT_PATH/makefile" ]; then
	fatal_error "\033[0;31mNo \033[0;35mMakefile \033[0;31mfound at \033[0;34m$LIBFT_PATH. \033[0;31mAborted.\033[0m" $EXIT_PATH_ERROR
fi

#Try to build the libft archive using the `make re or make fclean make bonus` command

if [ "$BONUS" = true ] || [ "$FULL" = true ]
then
	if [ "$RE" = true ]
	then
		echo -e "${LPROMPT}make fclean"
		make fclean -C $LIBFT_PATH > /dev/null || fatal_error "Error thrown by YOUR Makefile!" $EXIT_MAKE_ERROR
	fi
	echo -e "${LPROMPT}make bonus"
	make bonus -C $LIBFT_PATH >/dev/null || fatal_error "Error thrown by YOUR Makefile!" $EXIT_MAKE_ERROR
else
	if [ "$RE" = false ]
	then
		echo -e "${LPROMPT}make"
		make -C $LIBFT_PATH > /dev/null || fatal_error "Error thrown by YOUR Makefile!" $EXIT_MAKE_ERROR
	else
		echo -e "${LPROMPT}make re"
		make re -C $LIBFT_PATH > /dev/null || fatal_error "Error thrown by YOUR Makefile!" $EXIT_MAKE_ERROR
	fi
fi

# Check if archive has been generated, otherwise exit.
if [ ! -f "$LIBFT_PATH/libft.a" ]; then
	fatal_error "\033[0;31mCould not found your \033[0;34mlibft.a \033[0;31marchive. Aborted.\033m" $EXIT_MAKE_ERROR
fi

# Run part1 test runner
if [ "$PART1" = true ]
then
	echo -e "${LUPROMPT}make part1"
	make part1 LIBFT_PATH=$LIBFT_PATH
	build/part1 | tee logs/part1.logfile
fi

# Run part2 test runner
if [ "$PART2" = true ]
then
	echo -e "${LUPROMPT}make part2"
	make part2 LIBFT_PATH=$LIBFT_PATH > /dev/null
	build/part2 | tee logs/part2.logfile
fi

# Run full test runner
if [ "$FULL" = true ]
then
	echo -e "${LUPROMPT}make libft"
	make libft LIBFT_PATH=$LIBFT_PATH > /dev/null
	build/libft | tee logs/full.logfile
fi


# Run bonus test runner
if [ "$BONUS" = true ]
then
	echo -e "${LUPROMPT}make bonus"
	make bonus LIBFT_PATH=$LIBFT_PATH > /dev/null
	build/bonus | tee logs/bonus.logfile
fi

# Run the test runners for all the individual functions specified
# Ex: ./test ft_strdup ft_calloc ft_strnstr

for func in "${FUNCS[@]}"
do
	# If function is a bonus function, make bonus must be executed
	echo $func | grep "lst" > /dev/null
	if [ $? -eq 0 ]
	then
		echo -e "${LPROMPT}make bonus (*lst* detected)"
		make bonus -C $LIBFT_PATH > /dev/null || fatal_error "Error thrown by your Makefile while trying to make bonus part" $EXIT_MAKE_ERROR
	fi
	echo -e "${LUPROMPT}make $func"
	# Make the runner for the given function
	make ${func} LIBFT_PATH=$LIBFT_PATH 2> /dev/null
	# Execute the generated runner and tee the output in a logfile.
	if [ $? -eq 0 ];
	then
		build/$func | tee logs/$func.logfile
	#oopsie, not test runner available, function is probably not supported.
	else
		echo -e "\033[0;31mNo test runner for \033[0;34m$func \033[0;31mis available.\033[0m";
	fi
done
