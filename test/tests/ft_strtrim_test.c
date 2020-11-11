#include <string.h>
#include "tests.h"

void	ft_strtrim_simple_test(void)
{
	char	*ref = "Hello world";
	char	*totrim = "                            Hello world       \t";
	char	*trimed = NULL;

	trimed = ft_strtrim(totrim, " \t");
	to_free = trimed;
	TEST_ASSERT_EQUAL_STRING(ref, trimed);
}

void	ft_strtrim_bigtrim(void)
{
	char	*ref = "bb   Hello    world       how are you";
	char	*totrim = "    aa     a   a a    aa a  a   a a  a  x x x  x  x   bb   Hello    world       how are you                               a aaa                   a  a a axx";
	char	*trimed = NULL;

	trimed = ft_strtrim(totrim, "ax ");
	to_free = trimed;
	TEST_ASSERT_EQUAL_STRING(ref, trimed);
}
