#include <stdlib.h>
#include "tests.h"

extern t_list	*list_tofree;

void	ft_lstlast_simple_test(void)
{
	t_list	*head = NULL;
	t_list	*new1 = NULL;
	t_list	*new2 = NULL;

	head = calloc(1, sizeof(t_list));
	new1 = calloc(1, sizeof(t_list));
	new2 = calloc(1, sizeof(t_list));

	if (head && new1 && new2)
	{
		head->next = new1;
		head->next->next = new2;
		list_tofree = head;
		TEST_ASSERT_EQUAL_PTR(new2, ft_lstlast(head));
	}
	else
	{
		free(head);
		free(new1);
		free(new2);
	}
}

void	ft_lstlast_size1(void)
{
	t_list	*head = NULL;

	head = calloc(1, sizeof(t_list));
	if (head)
	{
		list_tofree = head;
		TEST_ASSERT_EQUAL_INT(head, ft_lstlast(head));
	}
	else
	{
		free(head);
	}
}
