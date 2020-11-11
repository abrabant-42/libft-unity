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

	RUN_TEST(ft_itoa_simple_test);
	RUN_TEST(ft_itoa_neg);
	RUN_TEST(ft_itoa_lower_bound);
	RUN_TEST(ft_itoa_upper_bound);
	RUN_TEST(ft_itoa_zero);

	return (UNITY_END());
}
