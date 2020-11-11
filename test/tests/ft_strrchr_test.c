#include <string.h>
#include "tests.h"

void	ft_strrchr_simple_test(void)
{
	char	*ref = "Hello world Hello boy Hello dude!";
	char	*rf = strrchr(ref, 'H');
	char	*ft = ft_strrchr(ref, 'H');

	TEST_ASSERT_EQUAL_PTR(rf, ft);
}

void	ft_strrchr_null(void)
{
	char	*ref = "Hello world Hello boy Hello dude!";
	char	*rf = strrchr(ref, 'X');
	char	*ft = ft_strrchr(ref, 'X');

	TEST_ASSERT_EQUAL_PTR(rf, ft);
}

void	ft_strrchr_null_byte(void)
{
	char	*ref = "Hello world Hello boy Hello dude!";
	char	*rf = strrchr(ref, 0);
	char	*ft = ft_strrchr(ref, 0);

	TEST_ASSERT_EQUAL_PTR(rf, ft);
}

void	ft_strrchr_8bits(void)
{
	char	*ref = "Hello worldé Hello boyé Hello dude!";
	char	*rf = strrchr(ref, 130);
	char	*ft = ft_strrchr(ref, 130);

	TEST_ASSERT_EQUAL_PTR(rf, ft);
}