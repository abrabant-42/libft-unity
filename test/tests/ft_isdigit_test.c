#include <string.h>
#include <ctype.h>
#include "tests.h"

/*
** It is said that isdigit and all the similar functions return non-zero
** as a true signal. The way this non-zero return value is computed is not
** known, and on Linux it is not simply 1 for true and 0 for false.
** Therefore the non-zero return value is the only thing to check here.
*/

void	ft_isdigit_simple_test(void)
{
	for (int c = '0'; c <= '9'; ++c)
		TEST_ASSERT(isdigit(c) != 0 && ft_isdigit(c) != 0);
}

void	ft_isdigit_false(void)
{
	for (int i = 0; i <= 127; ++i)
	{
		if (!isdigit(i))
			TEST_ASSERT_FALSE(ft_isdigit(i));
	}
}

void	ft_isdigit_EOF(void)
{
	const int	c = EOF; 

	TEST_ASSERT(isdigit(c) == 0 && ft_isdigit(c) == 0);
}