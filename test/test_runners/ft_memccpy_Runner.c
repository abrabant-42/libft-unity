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

	RUN_TEST(ft_memccpy_simple_test);
	RUN_TEST(ft_memccpy_8bits);
	RUN_TEST(ft_memccpy_lastis_c);
	RUN_TEST(ft_memccpy_before_c);
	RUN_TEST(ft_memccpy_zero);

	return (UNITY_END());
}
