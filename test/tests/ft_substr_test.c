#include <string.h>
#include <stdlib.h>
#include "tests.h"

void    ft_substr_simple_test(void)
{
	char	refbuf[] = "hello world!";
	char	*substr;

	substr = ft_substr(refbuf, 3, 6);
	to_free = substr;
	TEST_ASSERT_EQUAL_STRING("lo wor", substr);
}

void	ft_substr_zero_len(void)
{
	char	refbuf[] = "Hello";
	char	*substr;
	
	substr = ft_substr(refbuf, 2, 0);
	to_free = substr;
	TEST_ASSERT_EQUAL_STRING("", substr);
}

void	ft_substr_index_zero(void)
{
	char	refbuf[] = "Hello world!";
	char	*substr;

	substr = ft_substr(refbuf, 0, 5);
	to_free = substr;
	TEST_ASSERT_EQUAL_STRING("Hello", substr);
}

void	ft_substr_last_index(void)
{
	char	refbuf[] = "last character is a Z";
	char	*substr;

	substr = ft_substr(refbuf, 20, 1);
	to_free = substr;
	TEST_ASSERT_EQUAL_STRING("Z", substr);
}
