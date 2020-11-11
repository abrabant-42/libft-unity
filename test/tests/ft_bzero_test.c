#include <string.h>
#include "tests.h"

void	ft_bzero_simple_test(void)
{
	char refbuf[20] = { 'X' };
	char ftbuf[20] = { 'X' };

	bzero(refbuf, 10);
	ft_bzero(ftbuf, 10);

	TEST_ASSERT_EQUAL_MEMORY(refbuf, ftbuf, 20);
}