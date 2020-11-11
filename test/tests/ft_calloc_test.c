#include <string.h>
#include <stdlib.h>
#include "tests.h"

void	ft_calloc_simple_test(void)
{
	const size_t	nmemb = 5;
	const size_t	size = 4;
	char			tmp[size * nmemb];
	void			*rfbuf = NULL;
	void			*ftbuf = NULL;

	rfbuf = calloc(nmemb, size);
	ftbuf = ft_calloc(nmemb, size);
	memcpy(tmp, rfbuf, size * nmemb);
	free(rfbuf);
	to_free = ftbuf;

	TEST_ASSERT_EQUAL_MEMORY(tmp, ftbuf, size * nmemb);
}
