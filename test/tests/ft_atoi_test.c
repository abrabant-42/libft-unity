#include <string.h>
#include <stdlib.h>
#include "tests.h"

void	ft_atoi_simple_test(void)
{
	const char	*toparse = "54532";
	const int	ref = atoi(toparse);
	const int	ft = ft_atoi(toparse);

	TEST_ASSERT_EQUAL_INT(ref, ft);
}

void	ft_atoi_neg(void)
{
	const char	*toparse = "-54532";
	const int	ref = atoi(toparse);
	const int	ft = ft_atoi(toparse);

	TEST_ASSERT_EQUAL_INT(ref, ft);
}

void	ft_atoi_zero(void)
{
	const char	*toparse = "0";
	const int	ref = atoi(toparse);
	const int	ft = ft_atoi(toparse);

	TEST_ASSERT_EQUAL_INT(ref, ft);
}

void	ft_atoi_upper_bound(void)
{
	const char	*toparse = "2147483647";
	const int	ref = atoi(toparse);
	const int	ft = ft_atoi(toparse);

	TEST_ASSERT_EQUAL_INT(ref, ft);
}

void	ft_atoi_lower_bound(void)
{
	const char	*toparse = "-2147483648";
	const int	ref = atoi(toparse);
	const int	ft = ft_atoi(toparse);

	TEST_ASSERT_EQUAL_INT(ref, ft);
}

void	ft_atoi_invalid_format1(void)
{
	const char	*toparse = "+ 45";
	const int	ref = atoi(toparse);
	const int	ft = ft_atoi(toparse);

	TEST_ASSERT_EQUAL_INT(ref, ft);
}

void	ft_atoi_invalid_format2(void)
{
	const char	*toparse = "+--+-45";
	const int	ref = atoi(toparse);
	const int	ft = ft_atoi(toparse);

	TEST_ASSERT_EQUAL_INT(ref, ft);
}

void	ft_atoi_invalid_format3(void)
{
	const char	*toparse = " a45";
	const int	ref = atoi(toparse);
	const int	ft = ft_atoi(toparse);

	TEST_ASSERT_EQUAL_INT(ref, ft);
}

void	ft_atoi_invalid_format4(void)
{
	const char	*toparse = " 45a ";
	const int	ref = atoi(toparse);
	const int	ft = ft_atoi(toparse);

	TEST_ASSERT_EQUAL_INT(ref, ft);
}

void	ft_atoi_trailing_space(void)
{
	const char	*toparse = "\t\f   \v\t\t  -45     \n\r\r    ";
	const int	ref = atoi(toparse);
	const int	ft = ft_atoi(toparse);

	TEST_ASSERT_EQUAL_INT(ref, ft);
}
