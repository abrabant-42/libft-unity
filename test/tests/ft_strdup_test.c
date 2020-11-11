#include <string.h>
#include "tests.h"

void	ft_strdup_simple_test(void)
{
	char	*ref = "Hello world";
	char	*dup;

	dup = ft_strdup(ref);
	to_free = dup; 

	TEST_ASSERT_EQUAL_STRING(ref, dup);
	TEST_ASSERT(ref != dup); /* is memory address indeed different ? */
	dup[0] = 'X'; /* is it mutable, i.e allocated by malloc */
}
