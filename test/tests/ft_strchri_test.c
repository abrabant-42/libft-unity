#include <string.h>
#include "tests.h"

void	ft_strchri_simple_test(void)
{
	const char	*ref = "Hahwdjeawwaapekw[qpwrkawl/%weowr//";
	const int		refindex = 1; 
	const char	c = 'a';
	int			index = 0;

	index = ft_strchri(ref, c);
	TEST_ASSERT_EQUAL_INT(refindex, index);
}

void	ft_strchri_no_occurence(void)
{
	const char	*ref = "Hahwdjeowwoopekw[qpwrkowl/%weowr//";
	const int		refindex = -1; 
	const char	c = '-';
	int			index = 0;

	index = ft_strchri(ref, c);
	TEST_ASSERT_EQUAL_INT(refindex, index);
}
