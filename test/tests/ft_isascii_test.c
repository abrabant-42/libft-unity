#include <string.h>
#include <ctype.h>
#include "tests.h"

/*
** It is said that isascii and all the similar functions return non-zero
** as a true signal. The way this non-zero return value is computed is not
** known, and on Linux it is not simply 1 for true and 0 for false.
** Therefore the non-zero return value is the only thing to check here.
*/

void	ft_isascii_simple_test(void)
{
	for (int c = 0; c <= 127; ++c)
		TEST_ASSERT(isascii(c) != 0 && ft_isascii(c) != 0);
}

void	ft_isascii_EOF(void)
{
	const int	c = EOF; 

	TEST_ASSERT(isascii(c) == 0 && ft_isascii(c) == 0);
}
