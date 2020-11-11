#include <stdlib.h>
#include "tests.h"
#include "utils.h"

void	setUp()
{
}

void	tearDown()
{
}

int	main(void)
{
	catch_signals();

	UNITY_BEGIN();
	
	RUN_TEST(ft_lstclear_simple_test);

	return (UNITY_END());
}
