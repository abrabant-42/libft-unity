#include <string.h>
#include "tests.h"

void	ft_putendl_fd_simple_test(void)
{
	FILE		*fptr = NULL;
	const char	*ref = "hello world\n";
	const char	*s = "hello world";
	char		buf[strlen(s) + 2];
	size_t		i = 0;

	memset(buf, 0, strlen(s) + 2);
	fptr = fopen(".tmpfile", "w+");
	if (!fptr)
		TEST_IGNORE();
	ft_putendl_fd((char *)s, fileno(fptr));
	rewind(fptr);

	while ((buf[i] = fgetc(fptr)) != '\n' && buf[i] != EOF)
		++i;
	fclose(fptr);
	remove(".tmpfile");
	TEST_ASSERT_EQUAL_STRING(ref, buf);
}

void	ft_putendl_fd_cast(void)
{
	FILE		*fptr = NULL;
	const char	*ref = "éêaÂEe5êàXx\n";
	const char	*s = "éêaÂEe5êàXx";
	char		buf[strlen(s) + 2];
	size_t		i = 0;

	memset(buf, 0, strlen(s) + 2);
	fptr = fopen(".tmpfile", "w+");
	if (!fptr)
		TEST_IGNORE();
	ft_putendl_fd((char *)s, fileno(fptr));
	rewind(fptr);

	while ((buf[i] = fgetc(fptr)) != '\n' && buf[i] != EOF)
		++i;

	fclose(fptr);
	remove(".tmpfile");
	TEST_ASSERT_EQUAL_STRING(ref, buf);
}
