#include <string.h>
#include <ctype.h>
#include "tests.h"

/*
** It is said that isalpha and all the similar functions return non-zero
** as a true signal. The way this non-zero return value is computed is not
** known, and on Linux it is not simply 1 for true and 0 for false.
** Therefore the non-zero return value is the only thing to check here.
*/

void	ft_isalpha_simple_test(void)
{
	for (int c = 'A'; c < 'Z'; ++c)
		TEST_ASSERT(isalpha(c) != 0 && ft_isalpha(c) != 0);
	for (int c = 'a'; c < 'z'; ++c)
		TEST_ASSERT(isalpha(c) != 0 && ft_isalpha(c) != 0);
}

void	ft_isalpha_false(void)
{
	for (int c = 0; c <= 127; ++c)
	{
		if (!isalpha(c))
			TEST_ASSERT_FALSE(ft_isalpha(c));
	}
}

void	ft_isalpha_EOF(void)
{
	const int	c = EOF; 

	TEST_ASSERT(isalpha(c) == 0 && ft_isalpha(c) == 0);
}
