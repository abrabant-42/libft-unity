#ifndef TESTS_H
# define TESTS_H
# include "prototypes.h"
# include "unity.h"

extern char	global_buf[];
extern void	*to_free;

/* FT_SUBSTR */

void    ft_substr_simple_test(void);
void	ft_substr_oversized_len(void);
void	ft_substr_out_of_bounds(void);
void	ft_substr_zero_len(void);
void	ft_substr_index_zero(void);
void	ft_substr_last_index(void);
void	ft_substr_start_greater_than_or_equal_to_strlen(void);

/* FT_STRLWR */

void	ft_strlwr_simple_test(void);
void	ft_strlwr_with_7bytes_ascii(void);

/* FT_STRUPR */

void	ft_strupr_simple_test(void);
void	ft_strupr_with_7bytes_ascii(void);

/* FT_TOUPPER */

void	ft_toupper_simple_test(void);
void	ft_toupper_with_7bytes_ascii(void);

/* FT_TOLOWER */

void	ft_tolower_simple_test(void);
void	ft_tolower_with_7bytes_ascii(void);

/* FT_STRJOIN */

void	ft_strjoin_simple_test(void);

/* FT_STRINSRT */

void	ft_strinsrt_simple_test(void);
void	ft_strinsrt_index_out_of_bounds(void);
void	ft_strinsrt_last_index(void);
void	ft_strinsrt_first_index(void);

/* FT_SPLIT */

void	ft_split_simple_test(void);
void	ft_split_chained_delim(void);
void	ft_split_trailing_delim(void);

/* FT_STRREV */

void	ft_strrev_odd_string(void);
void	ft_strrev_even_string(void);

/* FT_STRTRIM */

void	ft_strtrim_simple_test(void);
void	ft_strtrim_nullset_test(void);
void	ft_strtrim_bigtrim(void);

/* FT_STRMAPI */

void	ft_strmapi_simple_test(void);
void	ft_strmapi_use_iterator(void);
void	ft_strmapi_null_f(void);

/* FT_TOUTF8 */

void	ft_toutf8_7bits_ascii(void);
void	ft_toutf8_2bytes_codepoint(void);
void	ft_toutf8_3bytes_codepoint(void);
void	ft_toutf8_4bytes_codepoint(void);

/* FT_STRUTF8 */

void	ft_strutf8_simple_test(void);

/* FT_STRCHRI */

void	ft_strchri_simple_test(void);
void	ft_strchri_no_occurence(void);

/* FT_LLTOB */

void	ft_lltob_simple_test(void);
void	ft_lltob_negative(void);
void	ft_lltob_abs_octal(void);
void	ft_lltob_abs_binary(void);
void	ft_lltob_abs_hex(void);
void	ft_lltob_neg_octal(void);
void	ft_lltob_abs_octal(void);
void	ft_lltob_abs_binary(void);
void	ft_lltob_abs_hex(void);
void	ft_lltob_neg_binary(void);
void	ft_lltob_neg_hex(void);
void	ft_lltob_upper_bound(void);
void	ft_lltob_lower_bound(void);
void	ft_lltob_invalid_base(void);
void	ft_lltob_zero(void);

/* FT_ULLTOB */

void	ft_ulltob_simple_test(void);
void	ft_ulltob_abs_octal(void);
void	ft_ulltob_abs_binary(void);
void	ft_ulltob_abs_hex(void);
void	ft_ulltob_abs_octal(void);
void	ft_ulltob_abs_binary(void);
void	ft_ulltob_abs_hex(void);
void	ft_ulltob_upper_bound(void);
void	ft_ulltob_invalid_base(void);
void	ft_ulltob_zero(void);

/* FT_ITOA */

void	ft_itoa_simple_test(void);
void	ft_itoa_neg(void);
void	ft_itoa_lower_bound(void);
void	ft_itoa_upper_bound(void);
void	ft_itoa_zero(void);

/* FT_INTLEN */

void	ft_intlen_simple_test(void);
void	ft_intlen_neg(void);
void	ft_intlen_zero(void);

/* FT_SET_BIT_COUNT */

void	ft_set_bit_count_simple_test(void);
void	ft_set_bit_count_ll_max(void);
void	ft_set_bit_count_ll_min(void);

/* FT_ATOI */

void	ft_atoi_simple_test(void);
void	ft_atoi_neg(void);
void	ft_atoi_zero(void);
void	ft_atoi_lower_bound(void);
void	ft_atoi_upper_bound(void);
void	ft_atoi_invalid_format1(void);
void	ft_atoi_invalid_format2(void);
void	ft_atoi_invalid_format3(void);
void	ft_atoi_invalid_format4(void);
void	ft_atoi_trailing_space(void);

/* FT_CALLOC */

void	ft_calloc_simple_test(void);

/* FT_BZERO */

void	ft_bzero_simple_test(void);

/* FT_ISALNUM */

void	ft_isalnum_simple_test(void);
void	ft_isalnum_false(void);
void	ft_isalnum_EOF(void);

/* FT_ISALPHA */

void	ft_isalpha_simple_test(void);
void	ft_isalpha_false(void);
void	ft_isalpha_EOF(void);

/* FT_ISDIGIT */

void	ft_isdigit_simple_test(void);
void	ft_isdigit_false(void);
void	ft_isdigit_EOF(void);

/* FT_ISASCII */

void	ft_isascii_simple_test(void);
void	ft_isascii_EOF(void);

/* FT_ISPRINT */

void	ft_isprint_simple_test(void);
void	ft_isprint_EOF(void);

/* FT_MEMSET */

void	ft_memset_simple_test(void);
void	ft_memset_8bits(void);
void	ft_memset_byte_overflow(void);

/* FT_MEMCPY */

void	ft_memcpy_simple_test(void);
void	ft_memcpy_8bits(void);

/* FT_MEMMOVE */

void	ft_memmove_simple_test(void);
void	ft_memmove_8bits(void);
void	ft_memmove_overlap(void);
void	ft_memmove_overlap_8bits(void);

/* FT_MEMCMP */

void	ft_memcmp_simple_test(void);
void	ft_memcmp_differs(void);
void	ft_memcmp_zero(void);
void	ft_memcmp_lastdiffers(void);

/* FT_MEMCCPY */

void	ft_memccpy_simple_test(void);
void	ft_memccpy_8bits(void);
void	ft_memccpy_lastis_c(void);
void	ft_memccpy_before_c(void);
void	ft_memccpy_zero(void);

/* FT_MEMCHR */

void	ft_memchr_simple_test(void);
void	ft_memchr_zero(void);
void	ft_memchr_notin_n(void);
void	ft_memchr_lastc(void);
void	ft_memchr_8bits(void);
void	ft_memchr_castc(void);

/* FT_STRNCMP */

void	ft_strncmp_simple_test(void);
void	ft_strncmp_equal(void);
void	ft_strncmp_equal_n(void);
void	ft_strncmp_zero(void);
void	ft_strncmp_8bits(void);
void	ft_strncmp_unequal_n(void);
void	ft_strncmp_unequal_last(void);

/* FT_STRCHR */

void	ft_strchr_simple_test(void);
void	ft_strchr_null(void);
void	ft_strchr_null_byte(void);
void	ft_strchr_8bits(void);

/* FT_STRRCHR */

void	ft_strrchr_simple_test(void);
void	ft_strrchr_null(void);
void	ft_strrchr_null_byte(void);
void	ft_strrchr_8bits(void);

/* FT_STRSTR */

void	ft_strnstr_simple_test(void);
void	ft_strnstr_not_found(void);
void	ft_strnstr_partial(void);
void	ft_strnstr_end(void);
void	ft_strnstr_start(void);
void	ft_strnstr_null_byte(void);

/* FT_STRDUP */

void	ft_strdup_simple_test(void);

/* FT_STRLCAT */

void	ft_strlcat_simple_test(void);
void	ft_strlcat_dest_full(void);
void	ft_strlcat_partial(void);
void	ft_strlcat_dstsize(void);

/* FT_STRLCPY */

void	ft_strlcpy_simple_test(void);
void	ft_strlcpy_zero(void);
void	ft_strlcpy_fullcopy(void);

/* FT_STRLEN */

void	ft_strlen_simple_test(void);
void	ft_strlen_empty_string(void);

/* FT_PUTCHAR_FD */

void	ft_putchar_fd_simple_test(void);
void	ft_putchar_fd_cast(void);

/* FT_PUTSTR_FD */

void	ft_putstr_fd_simple_test(void);
void	ft_putstr_fd_cast(void);

/* FT_PUTENDL_FD */

void	ft_putendl_fd_simple_test(void);
void	ft_putendl_fd_cast(void);

/* FT_PUTNBR_FD */

void	ft_putnbr_fd_simple_test(void);
void	ft_putnbr_fd_neg(void);
void	ft_putnbr_fd_max(void);
void	ft_putnbr_fd_min(void);


/*
** BONUS PART
*/

void	ft_lstnew_simple_test(void);

void	ft_lstadd_front_simple_test(void);

void	ft_lstsize_simple_test(void);
void	ft_lstsize_size1(void);


void	ft_lstlast_simple_test(void);
void	ft_lstlast_size1(void);

void	ft_lstdelone_simple_test(void);

void	ft_lstclear_simple_test(void);

void	ft_lstiter_simple_test(void);

void	ft_lstmap_simple_test(void);

void	ft_lstadd_back_simple_test(void);

#endif
