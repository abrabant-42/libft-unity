#include <stdlib.h>
#include <locale.h>
#include "utils.h"
#include "tests.h"

void	*to_free;

void	setUp(void)
{
	to_free = NULL;
}

void tearDown(void)
{
	free(to_free);
}

int	main(void)
{
	/* for utf-8 testing */
	setlocale(LC_ALL, "");

	catch_signals();

	UNITY_BEGIN();

	RUN_TEST(ft_substr_simple_test);
	RUN_TEST(ft_substr_zero_len);
	RUN_TEST(ft_substr_index_zero);
	RUN_TEST(ft_substr_last_index);
	RUN_TEST(ft_substr_start_greater_than_or_equal_to_strlen);

	RUN_TEST(ft_strjoin_simple_test);

	RUN_TEST(ft_split_simple_test);
	RUN_TEST(ft_split_chained_delim);
	RUN_TEST(ft_split_trailing_delim);

	RUN_TEST(ft_strtrim_simple_test);
	RUN_TEST(ft_strtrim_bigtrim);
	
	RUN_TEST(ft_strmapi_simple_test);
	RUN_TEST(ft_strmapi_use_iterator);
	
	RUN_TEST(ft_itoa_simple_test);
	RUN_TEST(ft_itoa_neg);
	RUN_TEST(ft_itoa_lower_bound);
	RUN_TEST(ft_itoa_upper_bound);
	RUN_TEST(ft_itoa_zero);

	RUN_TEST(ft_putstr_fd_simple_test);
	RUN_TEST(ft_putstr_fd_cast);

	RUN_TEST(ft_putchar_fd_simple_test);
	RUN_TEST(ft_putchar_fd_cast);

	RUN_TEST(ft_putendl_fd_simple_test);
	RUN_TEST(ft_putendl_fd_cast);

	RUN_TEST(ft_putnbr_fd_simple_test);
	RUN_TEST(ft_putnbr_fd_neg);
	RUN_TEST(ft_putnbr_fd_max);
	RUN_TEST(ft_putnbr_fd_min);

	return (UNITY_END());
}
