#include <string.h>
#include "tests.h"

void	ft_memcpy_simple_test(void)
{
	char	refbuf[20] = { 'X' };
	char	ftbuf[20] = { 'X' };
	void	*refmem;
	void	*ftmem;

	refmem = memcpy(refbuf, "Hello world", 10);
	ftmem = ft_memcpy(ftbuf, "Hello world", 10);

	TEST_ASSERT_EQUAL_MEMORY(refbuf, ftbuf, 20);
	TEST_ASSERT_EQUAL_PTR(ftbuf, ftmem);
}

void	ft_memcpy_8bits(void)
{
	char	refbuf[50] = { 'X' };
	char	ftbuf[50] = { 'X' };
	void	*refmem;
	void	*ftmem;

	refmem = memcpy(refbuf, "Ce test tu as aimé, sauf si t'as mal casté.", 43);
	ftmem = ft_memcpy(ftbuf, "Ce test tu as aimé, sauf si t'as mal casté.", 43);

	TEST_ASSERT_EQUAL_MEMORY(refbuf, ftbuf, 50);
	TEST_ASSERT_EQUAL_PTR(ftbuf, ftmem);
}