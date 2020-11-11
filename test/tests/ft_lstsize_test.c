#include <stdlib.h>
#include "tests.h"

extern t_list	*list_tofree;

void	ft_lstsize_simple_test(void)
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
		TEST_ASSERT_EQUAL_INT(ft_lstsize(head), 3);
	}
	else
	{
		free(head);
		free(new1);
		free(new2);
	}
}

void	ft_lstsize_size1(void)
{
	t_list	*head = NULL;

	head = calloc(1, sizeof(t_list));
	if (head)
	{
		list_tofree = head;
		TEST_ASSERT_EQUAL_INT(1, ft_lstsize(head));
	}
	else
	{
		free(head);
	}
}