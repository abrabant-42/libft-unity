#include <string.h>
#include "tests.h"

/*
** The map function will replace the mapped char by the next ascii character.
*/

static char	next_ascii(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}

/*
** Use the iterator and add it to the current character.
*/

static char	next_inth_ascii(unsigned int i, char c)
{
	return (c + i);
}

void	ft_strmapi_simple_test(void)
{
	char			refbuf[] = "Hello world!";		
	const char	*base = "Hello world!";
	char			*mapped = NULL;
	size_t		reflen = strlen(refbuf);

	/* Simulate the expected behavior */
	for (size_t j = 0; j < reflen; ++j)
	{
		++refbuf[j];
	}
	mapped = ft_strmapi(base, &next_ascii);
	to_free = mapped;
	TEST_ASSERT_EQUAL_STRING(refbuf, mapped);
}

void	ft_strmapi_use_iterator(void)
{
	char			refbuf[] = "Hello world!";		
	const char	*base = "Hello world!";
	char			*mapped = NULL;
	size_t		reflen = strlen(refbuf);

	/* Simulate the expected behavior */
	for (size_t j = 0; j < reflen; ++j)
	{
		refbuf[j] += j;
	}
	mapped = ft_strmapi(base, &next_inth_ascii);
	to_free = mapped;
	TEST_ASSERT_EQUAL_STRING(refbuf, mapped);
}

/*
** My implementation of an undefined behavior: if f is NULL then a duplicate
** is returned, without any changes. However if `s` is undefined the behavior
** is still undefined.
*/

void	ft_strmapi_null_f(void)
{
	const char	*ref = "Hello world how are you ?";
	const char	*base = "Hello world how are you ?";	
	char			*mapped = NULL;

	mapped = ft_strmapi(base, NULL);
	to_free = mapped;
	TEST_ASSERT_EQUAL_STRING(ref, mapped);
}
