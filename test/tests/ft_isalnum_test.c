#include <string.h>
#include <ctype.h>
#include "tests.h"

/*
** It is said that isalnum and all the similar functions return non-zero
** as a true signal. The way this non-zero return value is computed is not
** known, and on Linux it is not simply 1 for true and 0 for false.
** Therefore the non-zero return value is the only thing to check here.
*/

void	ft_isalnum_simple_test(void)
{
	for (int i = 0; i <= 127; ++i)
	{
		if (isalnum(i))
			TEST_ASSERT_TRUE(ft_isalnum(i));
	}
}

void	ft_isalnum_false(void)
{
	for (int i = 0; i <= 127; ++i)
	{
		if (!isalnum(i))
			TEST_ASSERT_FALSE(ft_isalnum(i));
	}
}

void	ft_isalnum_EOF(void)
{
	const int	c = EOF; 

	TEST_ASSERT(isalnum(c) == 0 && ft_isalnum(c) == 0);
}
