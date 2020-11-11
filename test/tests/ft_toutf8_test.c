#include <string.h>
#include "tests.h"

void	ft_toutf8_7bits_ascii(void)
{
	char		refbuf[100];
	uint32_t	cp    = 'A';
	char	*encoded = NULL;

	sprintf(refbuf, "%lc", cp);
	encoded = ft_toutf8(cp);
	to_free = encoded;
	TEST_ASSERT_EQUAL_STRING(refbuf, encoded);
}

void	ft_toutf8_2bytes_codepoint(void)
{
	char		refbuf[100];
	uint32_t	cp    = 0x90;
	char	*encoded = NULL;

	sprintf(refbuf, "%lc", cp);
	encoded = ft_toutf8(cp);
	to_free = encoded;
	TEST_ASSERT_EQUAL_STRING(refbuf, encoded);
}

void	ft_toutf8_3bytes_codepoint(void)
{
	char		refbuf[100];
	uint32_t	cp    = 0x900;
	char	*encoded = NULL;

	sprintf(refbuf, "%lc", cp);
	encoded = ft_toutf8(cp);
	to_free = encoded;
	TEST_ASSERT_EQUAL_STRING(refbuf, encoded);
}

void	ft_toutf8_4bytes_codepoint(void)
{
	char		refbuf[100];
	uint32_t	cp    = 0x11000;
	char	*encoded = NULL;

	sprintf(refbuf, "%lc", cp);
	encoded = ft_toutf8(cp);
	to_free = encoded;
	TEST_ASSERT_EQUAL_STRING(refbuf, encoded);
}
