#include <string.h>
#include "tests.h"

/*
** That's a pretty bare-bones function. NULL should not be handled, it is
** assumed to be programmer's responsability to care about this.
** __attribute__((nonnull)) is specified for s1 and s2 in the libft header.
*/

void	ft_strjoin_simple_test(void)
{
	char	refbuf[100] = { 0 };
	char	*s1 = "String 1";
	char	*s2 = "String 2";
	char	*joined = NULL;

	joined = ft_strjoin(s1, s2);
	to_free = joined;
	strcat(refbuf, s1);
	strcat(refbuf, s2);
	TEST_ASSERT_EQUAL_STRING(refbuf, joined);
}
