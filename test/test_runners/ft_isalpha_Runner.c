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

	RUN_TEST(ft_isalpha_simple_test);
	RUN_TEST(ft_isalpha_false);
	RUN_TEST(ft_isalpha_EOF);

	return (UNITY_END());
}
