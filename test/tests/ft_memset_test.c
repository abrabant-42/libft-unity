#include <string.h>
#include "tests.h"

void	ft_memset_simple_test(void)
{
	char	refbuf[20] = { 'X' };
	char	ftbuf[20] = { 'X' };
	void	*refmem;
	void	*ftmem;

	refmem = memset(refbuf, 'A', 10);
	ftmem = ft_memset(ftbuf, 'A', 10);

	TEST_ASSERT_EQUAL_MEMORY(refbuf, ftbuf, 20);
	TEST_ASSERT_EQUAL_PTR(ftbuf, ftmem);
}

void	ft_memset_8bits(void)
{
	char	refbuf[20] = { 'X' };
	char	ftbuf[20] = { 'X' };
	void	*refmem;
	void	*ftmem;

	refmem = memset(refbuf, 222, 15);
	ftmem = ft_memset(ftbuf, 222, 15);

	TEST_ASSERT_EQUAL_MEMORY(refbuf, ftbuf, 20);
	TEST_ASSERT_EQUAL_PTR(ftbuf, ftmem);
}

void	ft_memset_byte_overflow(void)
{
	char	refbuf[20] = { 'X' };
	char	ftbuf[20] = { 'X' };
	void	*refmem;
	void	*ftmem;

	refmem = memset(refbuf, 446983, 12);
	ftmem = ft_memset(ftbuf, 446983, 12);

	TEST_ASSERT_EQUAL_MEMORY(refbuf, ftbuf, 20);
	TEST_ASSERT_EQUAL_PTR(ftbuf, ftmem);
}