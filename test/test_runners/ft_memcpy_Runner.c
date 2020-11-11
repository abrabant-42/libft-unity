#include <string.h>
#include <stdlib.h>
#include "tests.h"
#include "utils.h"

void	*to_free;

void	setUp()
{
	to_free = NULL;
}

void	tearDown()
{
	free(to_free);
}

int	main(void)
{
	UNITY_BEGIN();

	catch_signals();

	RUN_TEST(ft_memcpy_simple_test);
	RUN_TEST(ft_memcpy_8bits);

	return (UNITY_END());
}
