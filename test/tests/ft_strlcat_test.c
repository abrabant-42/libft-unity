#include <string.h>
#include "tests.h"

/*
** To guarantee portability between Mac and Linux, these tests is not using
** strlcat(3) as it is not implemented on Linux by default.
** The reference values are hardcoded, on the basis of tests made with
** the real implementation where it is available.
*/

void	ft_strlcat_simple_test(void)
{
	char		ftdest[100] = "hello ";
	const char		*str = "world";
	const size_t	len = strlen(ftdest) + strlen(str) + 1;
	const size_t	rfrt = strlen(ftdest) + strlen(str);
	char		*rfdest = "hello world";
	size_t		ftrt;

	ftrt = ft_strlcat(ftdest, str, len);
	TEST_ASSERT_EQUAL_STRING(rfdest, ftdest);
	TEST_ASSERT_EQUAL_INT(rfrt, ftrt);
}

/*
** This test verifies the below manual instructions:
**
** "Note, however, that if strlcat() traverses size characters without finding a
** NUL, the length of the string is considered to be size and the destination
** string will not be NUL-terminated (since there was no space for the NUL)"
** - strlcat(3) on FreeBSD-based systems, such as MacOs.
** online ref: https://linux.die.net/man/3/strlcat
*/

void	ft_strlcat_dest_full(void)
{
	const char		*str = "Hello world";
	const size_t	len = 3;
	const size_t	rfrt = strlen(str) + len;
	char		ftdest[100] = "hello";
	char		*rfdest = "hello";
	size_t		ftrt;

	ftrt = ft_strlcat(ftdest, str, len);
	TEST_ASSERT_EQUAL_STRING(rfdest, ftdest);
	TEST_ASSERT_EQUAL_INT(rfrt, ftrt);
}

void	ft_strlcat_partial(void)
{
	char		ftdest[100] = "hello ";
	const char		*str = "world";
	const size_t	len = strlen(ftdest) + strlen(str);
	const size_t	rfrt = strlen(ftdest) + strlen(str);
	char		*rfdest = "hello worl";
	size_t		ftrt;

	ftrt = ft_strlcat(ftdest, str, len);
	TEST_ASSERT_EQUAL_STRING(rfdest, ftdest);
	TEST_ASSERT_EQUAL_INT(rfrt, ftrt);
}

void	ft_strlcat_dstsize(void)
{
	char		ftdest[100] = "hello ";
	const char		*str = "world";
	const size_t	len = strlen(ftdest);
	const size_t	rfrt = strlen(ftdest) + strlen(str);
	char		*rfdest = "hello ";
	size_t		ftrt;

	ftrt = ft_strlcat(ftdest, str, len);
	TEST_ASSERT_EQUAL_STRING(rfdest, ftdest);
	TEST_ASSERT_EQUAL_INT(rfrt, ftrt);
}