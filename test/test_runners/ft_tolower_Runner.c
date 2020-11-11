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

	RUN_TEST(ft_tolower_simple_test);
	RUN_TEST(ft_tolower_with_7bytes_ascii);

	return (UNITY_END());
}
