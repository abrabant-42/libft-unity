#include <stdlib.h>
#include "tests.h"

extern t_list	*list_tofree;

void	change_to_zero(void *element)
{
	*((int *)element) = 0;
}

void	ft_lstclear_simple_test(void)
{
	t_list	*head = NULL;
	t_list	*new1 = NULL;
	t_list	*new2 = NULL;
	int		nb1 = 45;
	int 	nb2 = 432;
	int 	nb3 = 32;

	head = calloc(1, sizeof(t_list));
	new1 = calloc(1, sizeof(t_list));
	new2 = calloc(1, sizeof(t_list));
	if (head && new1 && new2)
	{
		head->next = new1;
		head->next->next = new2;
		head->content = &nb1;
		new1->content = &nb2;
		new2->content = &nb3;
		ft_lstclear(&new1, &change_to_zero);
		free(head);
		TEST_ASSERT_NULL(new1); /* checks if list ptr has been set to NULL */
		/* checks if content has been cleaned -> for this test content must be set to 0 */
		TEST_ASSERT_EQUAL_INT(45, nb1); 
		TEST_ASSERT_EQUAL_INT(0, nb2); 
		TEST_ASSERT_EQUAL_INT(0, nb3);
	}
	else
	{
		free(head);
		free(new1);
		free(new2);
	}
}

