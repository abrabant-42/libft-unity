#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tests.h"

char err_msg[100];

static bool	verify_split(const char **ref, const char **test)
{
	size_t	i = 0;
	bool	found_not_equal = false;
	
	while (ref[i] && test[i])
	{
		if (strcmp(ref[i], test[i]) != 0)
		{
			found_not_equal = true;
			sprintf(err_msg, "Found unequal at index %ld: expected \"%s\", got \"%s\"", i, ref[i], test[i]);
		}
		++i;
	}
	if (!found_not_equal && (test[i] || ref[i])) 
	{
		found_not_equal = true;
		sprintf(err_msg, "test or ref was not NULL at the end of the comparison. Arrays length differ.");
	}
	i = 0;
	while (test[i])
		free((void *)test[i++]);
	free(test);
	return (!found_not_equal);
}

void	ft_split_simple_test(void)
{
	const char	*str = "Hello world How are you I am fine";
	const char	*ref[] = { "Hello", "world", "How", "are", "you", "I", "am", "fine", NULL };
	const char	delim = ' ';

	TEST_ASSERT_MESSAGE(verify_split(ref, (const char **)ft_split(str, delim)), err_msg);
}

void	ft_split_chained_delim(void)
{
	const char	*str = "Hello @@@@@@@world @@@@@@@@@@@@How@@@are y@@@@@@@@@@ou I am @@@@@@@@@@@fine";
	const char	*ref[] = { "Hello ", "world ", "How", "are y", "ou I am ", "fine",  NULL };
	const char	delim = '@';
	
	TEST_ASSERT_MESSAGE(verify_split(ref, (const char **)ft_split(str, delim)), err_msg);
}

void	ft_split_trailing_delim(void)
{
	const char	*str = "@@@@@@@@@@@@@@@@ Hello @@@@@@@world @@@@@@@@@@@@How@@@are y@@@@@@@@@@ou I am @@@@@@@@@@@fine @@@@@@@@@@@@@@@@";
	const char	*ref[] = { " Hello ", "world ", "How", "are y", "ou I am ", "fine ",  NULL };
	const char	delim = '@';
	
	TEST_ASSERT_MESSAGE(verify_split(ref, (const char **)ft_split(str, delim)), err_msg);
}
