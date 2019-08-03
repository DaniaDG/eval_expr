#include "eval.h"

operators_list	*ft_create_elem_o(char data)
{
	operators_list *list;

	list = (operators_list *)malloc(sizeof(operators_list));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}

void	o_list_push_front(operators_list **begin_list, char data)
{
	operators_list *list;

	list = ft_create_elem_o(data);
	list->next = *begin_list;
	*begin_list = list;
}

int	ft_list_size_o(operators_list *begin_list)
{
	operators_list	*list;
	int		i;

	if (!begin_list)
		return (0);
	list = begin_list;
	i = 1;
	while (list->next)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	o_list_clear(operators_list **begin_list)
{
	operators_list	*temp;
	operators_list	*list;

	list = *begin_list;
	temp = list->next;
	free(list);
	*begin_list = temp;
}
