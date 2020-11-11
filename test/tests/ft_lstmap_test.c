#include <stdlib.h>
#include "tests.h"

void	del(void *element)
{
	*((int *)element) = 0;
}

void	*map(void *element)
{
	int *nb = calloc(1, sizeof(int));

	if (!nb)
		TEST_IGNORE();
	*nb = *((int *)element) * 2;
	return (nb);
}

static void	clear_list(t_list *lst)
{
	t_list	*tmp = NULL;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	ft_lstmap_simple_test(void)
{
	t_list	*head = NULL;
	t_list	*new = NULL;
	t_list	*mapped = NULL;
	int		expected[2]= { 54 * 2, 23 * 2 };
	int		given[2];
	int		nb1 = expected[0] / 2;
	int		nb2 = expected[1] / 2;

	head = calloc(1, sizeof(t_list));
	new = calloc(1, sizeof(t_list));
	if (head && new)
	{
		head->next = new;
		head->content = &nb1;
		new->content = &nb2;
		mapped = ft_lstmap(head, &map, &del);
		given[0] = *((int *)mapped->content);
		given[1] = *((int *)mapped->next->content);
		clear_list(head);
		clear_list(mapped);
		TEST_ASSERT_EQUAL_INT_ARRAY(expected, given, 2);
	}
	else
	{
		free(head);
		free(new);
	}
}