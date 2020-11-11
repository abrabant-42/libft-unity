#include <string.h>
#include <stdlib.h>
#include "tests.h"
#include "utils.h"

void	*to_free = NULL;

void	setUp()
{
}

void	tearDown()
{
	free(to_free);
}

int	main(void)
{
	catch_signals();

	UNITY_BEGIN();

	RUN_TEST(ft_substr_simple_test);
	RUN_TEST(ft_substr_oversized_len);
	RUN_TEST(ft_substr_out_of_bounds);
	RUN_TEST(ft_substr_zero_len);
	RUN_TEST(ft_substr_index_zero);
	RUN_TEST(ft_substr_last_index);

	return (UNITY_END());
}
