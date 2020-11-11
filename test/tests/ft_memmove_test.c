#include <string.h>
#include "tests.h"

void	ft_memmove_simple_test(void)
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

void	ft_memmove_8bits(void)
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

void	ft_memmove_overlap(void)
{
	char	refbuf[50] = "Hello world, I hope this will not overlap badly.";
	char	ftbuf[50] = "Hello world, I hope this will not overlap badly.";
	void	*refmem;
	void	*ftmem;

	refmem = memmove(&refbuf[10], refbuf, 39);
	ftmem = ft_memmove(&ftbuf[10], ftbuf, 39);

	TEST_ASSERT_EQUAL_MEMORY(refbuf, ftbuf, 50);
	TEST_ASSERT_EQUAL_PTR(&ftbuf[10], ftmem);
}

void	ft_memmove_overlap_8bits(void)
{
	char	refbuf[50] = "Bjr monde, j'espère que t'as pas oublié le cast.";
	char	ftbuf[50] = "Bjr monde, j'espère que t'as pas oublié le cast.";
	void	*refmem;
	void	*ftmem;

	refmem = memmove(&refbuf[10], refbuf, 39);
	ftmem = ft_memmove(&ftbuf[10], ftbuf, 39);

	TEST_ASSERT_EQUAL_MEMORY(refbuf, ftbuf, 50);
	TEST_ASSERT_EQUAL_PTR(&ftbuf[10], ftmem);
}