#include <string.h>
#include <stdlib.h>
#include "tests.h"
#include "utils.h"

void	*to_free;

void	setUp(void)
{
	to_free = NULL;
}

void	tearDown(void)
{
	free(to_free);
}

int	main(void)
{
	catch_signals();

	UNITY_BEGIN();

	RUN_TEST(ft_split_simple_test);
	RUN_TEST(ft_split_chained_delim);
	RUN_TEST(ft_split_trailing_delim);

	return (UNITY_END());
}
