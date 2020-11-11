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

	RUN_TEST(ft_strnstr_simple_test);
	RUN_TEST(ft_strnstr_not_found);
	RUN_TEST(ft_strnstr_partial);
	RUN_TEST(ft_strnstr_end);
	RUN_TEST(ft_strnstr_start);
	RUN_TEST(ft_strnstr_null_byte);

	return (UNITY_END());
}
