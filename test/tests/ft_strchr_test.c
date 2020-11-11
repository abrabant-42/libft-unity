#include <string.h>
#include "tests.h"

void	ft_strchr_simple_test(void)
{
	char	*ref = "Hello world Hello boy Hello dude!";
	char	*rf = strchr(ref, 'H');
	char	*ft = ft_strchr(ref, 'H');

	TEST_ASSERT_EQUAL_PTR(rf, ft);
}

void	ft_strchr_null(void)
{
	char	*ref = "Hello world Hello boy Hello dude!";
	char	*rf = strchr(ref, 'X');
	char	*ft = ft_strchr(ref, 'X');

	TEST_ASSERT_EQUAL_PTR(rf, ft);
}

void	ft_strchr_null_byte(void)
{
	char	*ref = "Hello world Hello boy Hello dude!";
	char	*rf = strchr(ref, 0);
	char	*ft = ft_strchr(ref, 0);

	TEST_ASSERT_EQUAL_PTR(rf, ft);
}

void	ft_strchr_8bits(void)
{
	char	*ref = "Hello worldé Hello boyé Hello dude!";
	char	*rf = strchr(ref, 130);
	char	*ft = ft_strchr(ref, 130);

	TEST_ASSERT_EQUAL_PTR(rf, ft);
}