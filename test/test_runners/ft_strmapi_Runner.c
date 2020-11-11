#include <string.h>
#include <stdlib.h>
#include "tests.h"
#include "utils.h"

void	*to_free;
bool	fatal_error = false;

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

	RUN_TEST(ft_strmapi_simple_test);
	RUN_TEST(ft_strmapi_use_iterator);
	RUN_TEST(ft_strmapi_null_f);

	return (UNITY_END());
}
