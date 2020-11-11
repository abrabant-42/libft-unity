#include <string.h>
#include "tests.h"

void	ft_putstr_fd_simple_test(void)
{
	FILE		*fptr = NULL;
	const char	*s = "hello world";
	char		buf[strlen(s) + 1];

	memset(buf, 0, strlen(s) + 1);
	fptr = fopen(".tmpfile", "w+");
	if (!fptr)
		TEST_IGNORE();
	ft_putstr_fd((char *)s, fileno(fptr));
	rewind(fptr);

	for (size_t i = 0; i < strlen(s); ++i)
		buf[i] = fgetc(fptr);
	fclose(fptr);
	remove(".tmpfile");
	TEST_ASSERT_EQUAL_STRING(s, buf);
}

void	ft_putstr_fd_cast(void)
{
	FILE		*fptr = NULL;
	const char	*s = "éllo woré mifâ éntèrtainmeunte";
	char		buf[strlen(s) + 1];

	memset(buf, 0, strlen(s) + 1);
	fptr = fopen(".tmpfile", "w+");
	if (!fptr)
		TEST_IGNORE();
	ft_putstr_fd((char *)s, fileno(fptr));
	rewind(fptr);

	for (size_t i = 0; i < strlen(s); ++i)
		buf[i] = fgetc(fptr);

	fclose(fptr);
	remove(".tmpfile");
	TEST_ASSERT_EQUAL_STRING(s, buf);
}
