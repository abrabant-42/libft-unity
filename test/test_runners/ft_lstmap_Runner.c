#include <stdlib.h>
#include "tests.h"
#include "utils.h"

bool	fatal_error = false;

void	setUp()
{
	if (fatal_error) {
		fatal_crash();
	}
}

void	tearDown()
{
}

int	main(void)
{
	catch_signals();

	UNITY_BEGIN();

	RUN_TEST(ft_lstmap_simple_test);

	return (UNITY_END());
}
