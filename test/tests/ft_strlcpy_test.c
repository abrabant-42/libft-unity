#include <string.h>
#include "tests.h"

void	ft_strlcpy_simple_test(void)
{
	const size_t	len = 5;
	const char		*src = "Hello world";
	const char		*rfdest = "Hell";
	const size_t	rfrt = strlen(src);
	size_t			ftrt;
	char			ftdest[100];
	
	ftrt = ft_strlcpy(ftdest, src, len);

	TEST_ASSERT_EQUAL_STRING(rfdest, ftdest);
	TEST_ASSERT_EQUAL_INT(rfrt, ftrt);
}

/* Should not mutate anything in dst */

void	ft_strlcpy_zero(void)
{
	const size_t	len = 0;
	const char		*src = "Hello world";
	const char		*rfdest = "x";
	const size_t	rfrt = strlen(src);
	size_t			ftrt;
	char			ftdest[2] = "x";
	
	ftrt = ft_strlcpy(ftdest, src, len);

	TEST_ASSERT_EQUAL_STRING(rfdest, ftdest);
	TEST_ASSERT_EQUAL_INT(rfrt, ftrt);
}

void	ft_strlcpy_fullcopy(void)
{
	const size_t	len = 37;
	const char		*src = "Hello world";
	const char		*rfdest = "Hello world";
	const size_t	rfrt = strlen(src);
	size_t			ftrt;
	char			ftdest[100];
	
	ftrt = ft_strlcpy(ftdest, src, len);

	TEST_ASSERT_EQUAL_STRING(rfdest, ftdest);
	TEST_ASSERT_EQUAL_INT(rfrt, ftrt);
}