#include <string.h>
#include "tests.h"

/*
** memcmp must return 1, 0 or -1 depending on the comparison result.
** It is not supposed to return the difference: the return value is
** undefined, only the sign of it is guaranteed.
** Therefore it is the only thing evaluated.
*/

/* Should return 0 because only comparing 7 characters */

void	ft_memcmp_simple_test(void)
{
	const char	*s1 = "stringéstring2";
	const char	*s2 = "string2string1";
	int			ref = 0;
	int			ft = 0;

	ref = memcmp(s1, s2, 6);
	ft = ft_memcmp(s1, s2, 6);

	TEST_ASSERT_EQUAL_INT(ref, ft);
}

void	ft_memcmp_differs(void)
{
	const char	*s1 = "stringéstring2";
	const char	*s2 = "string2string1";
	int			ref = 0;
	int			ft = 0;

	ref = memcmp(s1, s2, 56);
	ft = ft_memcmp(s1, s2, 56);

	TEST_ASSERT(ref > 0 && ft > 0);
}

void	ft_memcmp_zero(void)
{
	const char	*s1 = "string1string2";
	const char	*s2 = "String2string1";
	int			ref = 0;
	int			ft = 0;

	ref = memcmp(s1, s2, 0);
	ft = ft_memcmp(s1, s2, 0);

	TEST_ASSERT(ref == 0 && ft == 0);
}

void	ft_memcmp_lastdiffers(void)
{
	const char	*s1 = "string2string2";
	const char	*s2 = "string4string1";
	int			ref = 0;
	int			ft = 0;

	ref = memcmp(s1, s2, 7);
	ft = ft_memcmp(s1, s2, 7);

	TEST_ASSERT(ref < 0 && ft < 0);
}
