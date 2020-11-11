#include <string.h>
#include <ctype.h>
#include "tests.h"

void	ft_tolower_simple_test(void)
{
	char	refbuf[] = "THIS IS A UPPERCASE STRING WITH lowercase too";
	char	*lower_ver = NULL;
	size_t	i = -1;

	lower_ver = strdup(refbuf);
	if (!lower_ver)
	{
		TEST_IGNORE();
	}
	while (refbuf[++i])
	{
		lower_ver[i] = ft_tolower(lower_ver[i]);
		refbuf[i] = tolower(refbuf[i]);
	}
	to_free = lower_ver;
	TEST_ASSERT_EQUAL_STRING(refbuf, lower_ver);
}

void	ft_tolower_with_7bytes_ascii(void)
{
	char	refbuf[] = "%@r93i9Upper ekeokrokr LOWER rkoerk lep@#$%^&&``~~";
	char	*lower_ver = NULL;
	size_t	i = -1;

	lower_ver = strdup(refbuf);
	if (!lower_ver)
		TEST_IGNORE();
	while (refbuf[++i])
	{
		lower_ver[i] = ft_tolower(lower_ver[i]);
		refbuf[i] = tolower(refbuf[i]);
	}
	to_free = lower_ver;
	TEST_ASSERT_EQUAL_STRING(refbuf, lower_ver);
}
