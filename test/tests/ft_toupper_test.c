#include <string.h>
#include <ctype.h>
#include "tests.h"

void	ft_toupper_simple_test(void)
{
	char	refbuf[] = "This is a lower case string with UPPERCASE TOO";
	char	*upper_ver = NULL;
	size_t	i = -1;

	upper_ver = strdup(refbuf);
	if (!upper_ver)
	{
		TEST_IGNORE();
	}
	while (refbuf[++i])
	{
		upper_ver[i] = ft_toupper(upper_ver[i]);
		refbuf[i] = toupper(refbuf[i]);
	}
	to_free = upper_ver;
	TEST_ASSERT_EQUAL_STRING(refbuf, upper_ver);
}

void	ft_toupper_with_7bytes_ascii(void)
{
	char	refbuf[] = "%@r93i9Upper ekeokrokr LOWER rkoerk lep@#$%^&&``~~";
	char	*upper_ver = NULL;
	size_t	i = -1;

	upper_ver = strdup(refbuf);
	if (!upper_ver)
	{
		TEST_IGNORE();
	}
	while (refbuf[++i])
	{
		upper_ver[i] = ft_toupper(upper_ver[i]);
		refbuf[i] = toupper(refbuf[i]);
	}
	to_free = upper_ver;
	TEST_ASSERT_EQUAL_STRING(refbuf, upper_ver);
}
