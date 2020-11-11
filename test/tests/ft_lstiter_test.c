#include <stdlib.h>
#include "tests.h"

extern	t_list *list_tofree;
int		array[10];
int		i = 0;

static void	store_integers(void *element)
{
	array[i++] = *((int *)element);
} 

void	ft_lstiter_simple_test(void)
{
	int expected[] = { 45, 432, 32 };
	t_list	*head = NULL;
	t_list	*new1 = NULL;
	t_list	*new2 = NULL;
	int		nb1 = expected[0];
	int 	nb2 = expected[1];
	int 	nb3 = expected[2];

	i = 0;
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
		list_tofree = head;
		ft_lstiter(head, &store_integers);
		TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, 3);
	}
}
