#include <string.h>
#include "tests.h"

/*
** strnstr is not included in the C standard and is not implemented on Linux
** by default. However, the real function is available on FreeBSD based OS.
*/

void	ft_strnstr_simple_test(void)
{
	const char	*haystack = "Hello world this is an haystack! I'am looking for a needle...";
	const char	*needle	= "needle";
	char	*ref;
	char	*ft;

	ref = (char *)haystack + 52; 
	ft = ft_strnstr(haystack, needle, 100);

	TEST_ASSERT_EQUAL_PTR(ref, ft);
}

void	ft_strnstr_not_found(void)
{
	const char	*haystack = "Hello world this is an haystack! I'am looking for a Needle...";
	const char	*needle	= "needle";
	char	*ref;
	char	*ft;

	ref = NULL;
	ft = ft_strnstr(haystack, needle, 100);

	TEST_ASSERT_EQUAL_PTR(ref, ft);
}

/* Needle is partially matched, but len prevents scanning it entirely. */

void	ft_strnstr_partial(void)
{
	const char	*haystack = "Hello world thisno is an haystack! I'am looking for a Needle...";
	const char	*needle	= "no";
	char	*ref;
	char	*ft;

	ref = NULL;
	ft = ft_strnstr(haystack, needle, 17);

	TEST_ASSERT_EQUAL_PTR(ref, ft);
}

void	ft_strnstr_end(void)
{
	const char	*haystack = "Hello world";
	const char	*needle	= "ld";
	char	*ref;
	char	*ft;

	ref = (char *)haystack + 9;
	ft = ft_strnstr(haystack, needle, 15);

	TEST_ASSERT_EQUAL_PTR(ref, ft);
}

void	ft_strnstr_start(void)
{
	const char	*haystack = "Hello world";
	const char	*needle	= "He";
	char	*ref;
	char	*ft;

	ref = (char *)haystack;
	ft = ft_strnstr(haystack, needle, 15);

	TEST_ASSERT_EQUAL_PTR(ref, ft);
}

/* This should return a pointer to the beginning of the haystack */

void	ft_strnstr_null_byte(void)
{
	const char	*haystack = "Hello world";
	const char	*needle	= "\0";
	char	*ref;
	char	*ft;

	ref = (char *)haystack;
	ft = ft_strnstr(haystack, needle, 15);

	TEST_ASSERT_EQUAL_PTR(ref, ft);
}