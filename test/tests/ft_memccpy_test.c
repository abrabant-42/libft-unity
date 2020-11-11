#include <string.h>
#include "tests.h"

void	ft_memccpy_simple_test(void)
{
	char	refbuf[20] = "uwurur9uwruwr9uw9uws";
	char	tmp[20];
	void	*refmem;
	void	*ftmem;

	refmem = memccpy(tmp, "Hello| world", '|', 10);
	memcpy(refbuf, tmp, 20);
	ftmem = ft_memccpy(tmp, "Hello| world", '|', 10);

	TEST_ASSERT_EQUAL_MEMORY(refbuf, tmp, 20);
	TEST_ASSERT_EQUAL_PTR(refmem, ftmem);
}

void	ft_memccpy_before_c(void)
{
	char	refbuf[20]; 
	char	tmp[20];
	void	*refmem;
	void	*ftmem;

	refmem = memccpy(tmp, "Hello| world", '|', 5);
	memcpy(refbuf, tmp, 20);
	ftmem = ft_memccpy(tmp, "Hello| world", '|', 5);

	TEST_ASSERT_EQUAL_MEMORY(refbuf, tmp, 20);
	TEST_ASSERT_EQUAL_PTR(refmem, ftmem);
}

void	ft_memccpy_lastis_c(void)
{
	char	refbuf[20]; 
	char	tmp[20];
	void	*refmem;
	void	*ftmem;

	refmem = memccpy(tmp, "Hello| world", '|', 6);
	memcpy(refbuf, tmp, 20);
	ftmem = ft_memccpy(tmp, "Hello| world", '|', 6);

	TEST_ASSERT_EQUAL_MEMORY(refbuf, tmp, 20);
	TEST_ASSERT_EQUAL_PTR(refmem, ftmem);
}

void	ft_memccpy_zero(void)
{
	char	refbuf[20] = {0}; 
	char	tmp[20] = {0};
	void	*refmem;
	void	*ftmem;

	refmem = memccpy(tmp, "Hello| world", '|', 0);
	memcpy(refbuf, tmp, 20);
	ftmem = ft_memccpy(tmp, "Hello| world", '|', 0);

	TEST_ASSERT_EQUAL_MEMORY(refbuf, tmp, 20);
	TEST_ASSERT_EQUAL_PTR(refmem, ftmem);
}

void	ft_memccpy_8bits(void)
{
	char	refbuf[50];
	char	tmp[50];
	void	*refmem;
	void	*ftmem;

	refmem = memccpy(tmp, "Hello world, ébahi par la qualité du cast.", '|', 44);
	memcpy(refbuf, tmp, 50);
	ftmem = ft_memccpy(tmp, "Hello world, ébahi par la qualité du cast.", '|', 44);

	TEST_ASSERT_EQUAL_MEMORY(refbuf, tmp, 20);
	TEST_ASSERT_EQUAL_PTR(refmem, ftmem);
}