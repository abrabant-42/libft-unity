#include <string.h>
#include "tests.h"

void	ft_putnbr_fd_simple_test(void)
{
	FILE		*fptr;
	const int	n = 2345;
	const char	*ref = "2345";
	char		buf[strlen(ref) + 1];

	memset(buf, 0, strlen(ref) + 1);
	fptr = fopen(".tmpfile", "w+");
	if (!fptr)
		TEST_IGNORE();
	ft_putnbr_fd(n, fileno(fptr));
	rewind(fptr);
	for (size_t i = 0; i < strlen(ref); ++i)
		buf[i] = fgetc(fptr);
	TEST_ASSERT_EQUAL_STRING(ref, buf);
}

void	ft_putnbr_fd_neg(void)
{
	FILE		*fptr;
	const int	n = -2345;
	const char	*ref = "-2345";
	char		buf[strlen(ref) + 1];

	memset(buf, 0, strlen(ref) + 1);
	fptr = fopen(".tmpfile", "w+");
	if (!fptr)
		TEST_IGNORE();
	ft_putnbr_fd(n, fileno(fptr));
	rewind(fptr);
	for (size_t i = 0; i < strlen(ref); ++i)
		buf[i] = fgetc(fptr);
	TEST_ASSERT_EQUAL_STRING(ref, buf);
}

void	ft_putnbr_fd_max(void)
{
	FILE		*fptr;
	const int	n = 2147483647;
	const char	*ref = "2147483647";
	char		buf[strlen(ref) + 1];

	memset(buf, 0, strlen(ref) + 1);
	fptr = fopen(".tmpfile", "w+");
	if (!fptr)
		TEST_IGNORE();
	ft_putnbr_fd(n, fileno(fptr));
	rewind(fptr);
	for (size_t i = 0; i < strlen(ref); ++i)
		buf[i] = fgetc(fptr);
	TEST_ASSERT_EQUAL_STRING(ref, buf);
}

void	ft_putnbr_fd_min(void)
{
	FILE		*fptr;
	const int	n = -2147483648;
	const char	*ref = "-2147483648";
	char		buf[strlen(ref) + 1];

	memset(buf, 0, strlen(ref) + 1);
	fptr = fopen(".tmpfile", "w+");
	if (!fptr)
		TEST_IGNORE();
	ft_putnbr_fd(n, fileno(fptr));
	rewind(fptr);
	for (size_t i = 0; i < strlen(ref); ++i)
		buf[i] = fgetc(fptr);
	TEST_ASSERT_EQUAL_STRING(ref, buf);
}
