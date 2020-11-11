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

	RUN_TEST(ft_memmove_simple_test);
	RUN_TEST(ft_memmove_8bits);
	RUN_TEST(ft_memmove_overlap);
	RUN_TEST(ft_memmove_overlap_8bits);

	return (UNITY_END());
}
