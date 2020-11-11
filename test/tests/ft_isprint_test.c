#include <string.h>
#include <ctype.h>
#include "tests.h"

/*
** It is said that isprint and all the similar functions return non-zero
** as a true signal. The way this non-zero return value is computed is not
** known, and on Linux it is not simply 1 for true and 0 for false.
** Therefore the non-zero return value is the only thing to check here.
*/

void	ft_isprint_simple_test(void)
{
	for (int i = 0; i < 32; ++i)
		TEST_ASSERT(isprint(i) == 0 && ft_isprint(i) == 0);
	for (int i = 32; i < 127; ++i)
		TEST_ASSERT(isprint(i) > 0 && ft_isprint(i) > 0);
	TEST_ASSERT(isprint(127) == 0 && ft_isprint(127) == 0);
}

void	ft_isprint_EOF(void)
{
	TEST_ASSERT(isprint(EOF) == 0 && ft_isprint(EOF) == 0);
}