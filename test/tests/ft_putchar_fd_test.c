#include <string.h>
#include <stdio.h>
#include "tests.h"

void	ft_putchar_fd_simple_test(void)
{
	FILE				*fptr;
	const unsigned char	refc = 'c';
	unsigned char		c = 0;

	fptr = fopen(".tmpfile", "w+");
	if (!fptr)
		TEST_IGNORE();
	ft_putchar_fd(refc, fileno(fptr));
	rewind(fptr);
	c = fgetc(fptr);

	fclose(fptr);
	remove(".tmpfile");
	TEST_ASSERT_EQUAL_INT8(refc, c);
}

void	ft_putchar_fd_cast(void)
{
	FILE				*fptr;
	const unsigned char	refc = 'c';
	unsigned char		c = 130;

	fptr = fopen(".tmpfile", "w+");
	if (!fptr)
		TEST_IGNORE();
	ft_putchar_fd(refc, fileno(fptr));
	rewind(fptr);
	c = fgetc(fptr);

	fclose(fptr);
	remove(".tmpfile");
	TEST_ASSERT_EQUAL_INT8(refc, c);
}