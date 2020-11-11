#include <string.h>
#include "tests.h"

/*
** strncmp often returns the difference between the first two characters 
** that differs. However, the standard only guarantees the sign of the
** return value. Therefore, this is the only thing tested.
*/

void	ft_strncmp_simple_test(void)
{
	const char	*s1 = "Hello world";
	const char	*s2 = "Hello boy";
	int			ref;
	int			ft;

	ref = strncmp(s1, s2, 9);
	ft = ft_strncmp(s1, s2, 9);

	TEST_ASSERT(ref > 0 && ft > 0);
}

void	ft_strncmp_equal(void)
{
	const char	*s1 = "Hello world";
	const char	*s2 = "Hello world";
	int			ref;
	int			ft;

	ref = strncmp(s1, s2, 12);
	ft = ft_strncmp(s1, s2, 12);

	TEST_ASSERT(ref == 0 && ft == 0);
}

void	ft_strncmp_equal_n(void)
{
	const char	*s1 = "Heleo world";
	const char	*s2 = "Hello world";
	int			ref;
	int			ft;

	ref = strncmp(s1, s2, 3);
	ft = ft_strncmp(s1, s2, 3);

	TEST_ASSERT(ref == 0 && ft == 0);
}

void	ft_strncmp_unequal_n(void)
{
	const char	*s1 = "HellO world";
	const char	*s2 = "Hello world";
	int			ref;
	int			ft;

	ref = strncmp(s1, s2, 5);
	ft = ft_strncmp(s1, s2, 5);

	TEST_ASSERT(ref < 0 && ft < 0);
}

void	ft_strncmp_unequal_last(void)
{
	const char	*s1 = "Hello world";
	const char	*s2 = "Hello worlD";
	int			ref;
	int			ft;

	ref = strncmp(s1, s2, 11);
	ft = ft_strncmp(s1, s2, 11);

	TEST_ASSERT(ref > 0 && ft > 0);
}

void	ft_strncmp_zero(void)
{
	const char	*s1 = "Hello world";
	const char	*s2 = "Hello world";
	int			ref;
	int			ft;

	ref = strncmp(s1, s2, 0);
	ft = ft_strncmp(s1, s2, 0);

	TEST_ASSERT_EQUAL_INT(ref, ft);
}

void	ft_strncmp_8bits(void)
{
	const char	*s1 = "Hello éworld";
	const char	*s2 = "Hello êworld";
	int			ref;
	int			ft;

	ref = strncmp(s1, s2, 9);
	ft = ft_strncmp(s1, s2, 9);

	TEST_ASSERT(ref < 0 && ft < 0);
}