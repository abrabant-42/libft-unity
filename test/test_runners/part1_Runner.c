#include <stdlib.h>
#include <locale.h>
#include "utils.h"
#include "tests.h"
#include <string.h>

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

	RUN_TEST(ft_toupper_simple_test);
	RUN_TEST(ft_toupper_with_7bytes_ascii);

	RUN_TEST(ft_tolower_simple_test);
	RUN_TEST(ft_tolower_with_7bytes_ascii);

	RUN_TEST(ft_atoi_simple_test);
	RUN_TEST(ft_atoi_neg);
	RUN_TEST(ft_atoi_zero);
	RUN_TEST(ft_atoi_upper_bound);
	RUN_TEST(ft_atoi_lower_bound);
	RUN_TEST(ft_atoi_invalid_format1);
	RUN_TEST(ft_atoi_invalid_format2);
	RUN_TEST(ft_atoi_invalid_format3);
	RUN_TEST(ft_atoi_invalid_format4);
	RUN_TEST(ft_atoi_trailing_space);

	RUN_TEST(ft_calloc_simple_test);

	RUN_TEST(ft_bzero_simple_test);

	RUN_TEST(ft_isalnum_simple_test);
	RUN_TEST(ft_isalnum_false);
	RUN_TEST(ft_isalnum_EOF);

	RUN_TEST(ft_isalpha_simple_test);
	RUN_TEST(ft_isalpha_false);
	RUN_TEST(ft_isalpha_EOF);

	RUN_TEST(ft_isdigit_simple_test);
	RUN_TEST(ft_isdigit_false);
	RUN_TEST(ft_isdigit_EOF);

	RUN_TEST(ft_isascii_simple_test);
	RUN_TEST(ft_isascii_EOF);

	RUN_TEST(ft_isprint_simple_test);
	RUN_TEST(ft_isprint_EOF);

	RUN_TEST(ft_memcpy_simple_test);
	RUN_TEST(ft_memcpy_8bits);

	RUN_TEST(ft_memset_simple_test);
	RUN_TEST(ft_memset_8bits);
	RUN_TEST(ft_memset_byte_overflow);

	RUN_TEST(ft_memmove_simple_test);
	RUN_TEST(ft_memmove_8bits);
	RUN_TEST(ft_memmove_overlap);
	RUN_TEST(ft_memmove_overlap_8bits);

	RUN_TEST(ft_memcmp_simple_test);
	RUN_TEST(ft_memcmp_zero);
	RUN_TEST(ft_memcmp_differs);
	RUN_TEST(ft_memcmp_lastdiffers);

	RUN_TEST(ft_memccpy_simple_test);
	RUN_TEST(ft_memccpy_8bits);
	RUN_TEST(ft_memccpy_lastis_c);
	RUN_TEST(ft_memccpy_before_c);
	RUN_TEST(ft_memccpy_zero);

	RUN_TEST(ft_memchr_simple_test);
	RUN_TEST(ft_memchr_zero);
	RUN_TEST(ft_memchr_notin_n);
	RUN_TEST(ft_memchr_8bits);
	RUN_TEST(ft_memchr_lastc);
	RUN_TEST(ft_memchr_castc);

	RUN_TEST(ft_strncmp_simple_test);
	RUN_TEST(ft_strncmp_zero);
	RUN_TEST(ft_strncmp_unequal_last);
	RUN_TEST(ft_strncmp_unequal_n);
	RUN_TEST(ft_strncmp_equal);
	RUN_TEST(ft_strncmp_equal_n);
	RUN_TEST(ft_strncmp_8bits);

	RUN_TEST(ft_strchr_simple_test);
	RUN_TEST(ft_strchr_null);
	RUN_TEST(ft_strchr_null_byte);
	RUN_TEST(ft_strchr_8bits);

	RUN_TEST(ft_strrchr_simple_test);
	RUN_TEST(ft_strrchr_null);
	RUN_TEST(ft_strrchr_null_byte);
	RUN_TEST(ft_strrchr_8bits);

	RUN_TEST(ft_strnstr_simple_test);
	RUN_TEST(ft_strnstr_not_found);
	RUN_TEST(ft_strnstr_partial);
	RUN_TEST(ft_strnstr_end);
	RUN_TEST(ft_strnstr_start);
	RUN_TEST(ft_strnstr_null_byte);

	RUN_TEST(ft_strdup_simple_test)	;

	RUN_TEST(ft_strlcat_dest_full);
	RUN_TEST(ft_strlcat_simple_test);
	RUN_TEST(ft_strlcat_partial);

	RUN_TEST(ft_strlcpy_simple_test);
	RUN_TEST(ft_strlcpy_zero);
	RUN_TEST(ft_strlcpy_fullcopy);

	return (UNITY_END());
}
