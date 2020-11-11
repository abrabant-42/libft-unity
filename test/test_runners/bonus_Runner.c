#include <stdlib.h>
#include <locale.h>
#include "utils.h"
#include "tests.h"
#include <string.h>

t_list	*list_tofree;

void	setUp(void)
{
	list_tofree = NULL;
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
}

int	main(void)
{
	/* for utf-8 testing */
	setlocale(LC_ALL, "");

	catch_signals();

	UNITY_BEGIN();

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
