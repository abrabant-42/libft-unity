#include <stdlib.h>
#include <locale.h>
#include <signal.h>
#include <string.h>
#include "utils.h"
#include "tests.h"

t_list	*list_tofree;
void	*to_free;

void	setUp(void)
{
	list_tofree = NULL;
	to_free = NULL;
}

void tearDown(void)
{
	t_list	*cur = list_tofree;
	t_list	*tmp = NULL;

	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	free(to_free);
}

int	main(void)
{
	/* for utf-8 testing */
	setlocale(LC_ALL, "");

	catch_signals();

	UNITY_BEGIN();

	/* PART 1 RUNNER */

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

	/* PART 2 RUNNER */

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

	RUN_TEST(ft_lstmap_simple_test); 
	RUN_TEST(ft_lstnew_simple_test);
	RUN_TEST(ft_lstsize_simple_test);
	RUN_TEST(ft_lstsize_size1);
	RUN_TEST(ft_lstclear_simple_test);
	RUN_TEST(ft_lstdelone_simple_test);
	RUN_TEST(ft_lstiter_simple_test);
	RUN_TEST(ft_lstadd_front_simple_test);
	RUN_TEST(ft_lstadd_back_simple_test);

	return (UNITY_END());
}
