#include <string.h>
#include "tests.h"

void	ft_lstnew_simple_test(void)
{
	t_list	*new;
	int		nb = 45;

	new = ft_lstnew(&nb);

	TEST_ASSERT_EQUAL_INT(nb, *((int *)new->content));
	TEST_ASSERT_NULL(new->next);
}
