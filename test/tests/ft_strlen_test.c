#include <string.h>
#include "tests.h"

void	ft_strlen_simple_test(void)
{
	char	*ref = "hello world this is a string";

	TEST_ASSERT_EQUAL_INT(strlen(ref), ft_strlen(ref));
}

void	ft_strlen_empty_string(void)
{
	char	*ref = "";

	TEST_ASSERT_EQUAL_INT(strlen(ref), ft_strlen(ref));
}