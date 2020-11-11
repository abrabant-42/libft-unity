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
	catch_signals();

	UNITY_BEGIN();

	RUN_TEST(ft_memchr_simple_test);
	RUN_TEST(ft_memchr_zero);
	RUN_TEST(ft_memchr_notin_n);
	RUN_TEST(ft_memchr_8bits);
	RUN_TEST(ft_memchr_lastc);
	RUN_TEST(ft_memchr_castc);

	return (UNITY_END());
}
