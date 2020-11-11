#include <string.h>
#include "tests.h"

void	ft_itoa_simple_test(void)
{
	char	*ref = "2436";
	int	nb = 2436;
	char	*str = NULL;

	to_free = str = ft_itoa(nb);
	TEST_ASSERT_EQUAL_STRING(ref, str);
}

void	ft_itoa_neg(void)
{
	char	*ref = "-2436";
	int	nb = -2436;
	char	*str = NULL;

	to_free = str = ft_itoa(nb);
	TEST_ASSERT_EQUAL_STRING(ref, str);
}

void	ft_itoa_lower_bound(void)
{
	char	*ref = "-2147483648";
	int	nb = INT_MIN;
	char	*str = NULL;

	to_free = str = ft_itoa(nb);
	TEST_ASSERT_EQUAL_STRING(ref, str);
}

void	ft_itoa_upper_bound(void)
{
	char	*ref = "2147483647";
	int	nb = INT_MAX;
	char	*str = NULL;

	to_free = str = ft_itoa(nb);
	TEST_ASSERT_EQUAL_STRING(ref, str);
}

void	ft_itoa_zero(void)
{
	char	*ref = "0";
	int	nb = 0;
	char	*str = NULL;

	to_free = str = ft_itoa(nb);
	TEST_ASSERT_EQUAL_STRING(ref, str);
}
