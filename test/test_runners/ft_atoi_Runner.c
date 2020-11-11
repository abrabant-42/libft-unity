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

	RUN_TEST(ft_atoi_simple_test);
	RUN_TEST(ft_atoi_neg);
	RUN_TEST(ft_atoi_zero);
	RUN_TEST(ft_atoi_upper_bound);
	RUN_TEST(ft_atoi_lower_bound);
	RUN_TEST(ft_atoi_invalid_format1);
	RUN_TEST(ft_atoi_invalid_format2);
	RUN_TEST(ft_atoi_invalid_format3);
	RUN_TEST(ft_atoi_invalid_format4);
	RUN_TEST(ft_atoi_trailing_space);

	return (UNITY_END());
}
