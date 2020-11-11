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

	RUN_TEST(ft_strncmp_simple_test);
	RUN_TEST(ft_strncmp_zero);
	RUN_TEST(ft_strncmp_unequal_last);
	RUN_TEST(ft_strncmp_unequal_n);
	RUN_TEST(ft_strncmp_equal);
	RUN_TEST(ft_strncmp_equal_n);
	RUN_TEST(ft_strncmp_8bits);

	return (UNITY_END());
}
