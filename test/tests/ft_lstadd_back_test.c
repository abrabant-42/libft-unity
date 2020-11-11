#include <stdlib.h>
#include "tests.h"

extern t_list	*list_tofree;

void	ft_lstadd_back_simple_test(void)
{
	t_list	*head = NULL;
	t_list	*new = NULL;

	head = calloc(1, sizeof(t_list));
	new = calloc(1, sizeof(t_list));
	if (head && new)
	{
		head->next = NULL;
		new->next = NULL;
		ft_lstadd_back(&head, new);
		list_tofree = head;
		TEST_ASSERT_EQUAL_PTR(new, head->next);
	}
	else
	{
		free(head);
		free(new);
	}
}