#include <string.h>
#include "tests.h"

void	ft_memchr_simple_test(void)
{
	char	*refstr	= "Hello world";
	void	*ref;
	void	*ft;

	ref = memchr(refstr, 'e', 6);
	ft = ft_memchr(refstr, 'e', 6);

	TEST_ASSERT_EQUAL_PTR(ref, ft);
}

void	ft_memchr_zero(void)
{
	char	*refstr	= "Hello world";
	void	*ref;
	void	*ft;

	ref = memchr(refstr, 'e', 0);
	ft = ft_memchr(refstr, 'e', 0);

	TEST_ASSERT_EQUAL_PTR(ref, ft);
}

void	ft_memchr_notin_n(void)
{
	char	*refstr	= "Hello world";
	void	*ref;
	void	*ft;

	ref = memchr(refstr, 'w', 6);
	ft = ft_memchr(refstr, 'w', 6);

	TEST_ASSERT_EQUAL_PTR(ref, ft);
}

void	ft_memchr_lastc(void)
{
	char	*refstr	= "Hello world";
	void	*ref;
	void	*ft;

	ref = memchr(refstr, 'w', 7);
	ft = ft_memchr(refstr, 'w', 7);

	TEST_ASSERT_EQUAL_PTR(ref, ft);
}

void	ft_memchr_8bits(void)
{
	char	*refstr	= "Hello étêî";
	void	*ref;
	void	*ft;

	ref = memchr(refstr, 130, 45);
	ft = ft_memchr(refstr, 130, 45);

	TEST_ASSERT_EQUAL_PTR(ref, ft);
}

/*
** 550 is 38 (&) when casted to unsigned char.
*/

void	ft_memchr_castc(void)
{
	char	*refstr	= "Hello && world";
	void	*ref;
	void	*ft;

	ref = memchr(refstr, 550, 12);
	ft = ft_memchr(refstr, 550, 12);

	TEST_ASSERT_EQUAL_PTR(ref, ft);
}