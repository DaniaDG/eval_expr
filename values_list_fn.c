#include "eval.h"

values_list	*ft_create_elem_v(int data)
{
	values_list *list;

	list = (values_list *)malloc(sizeof(values_list));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}

void	v_list_push_front(values_list **begin_list, int data)
{
	values_list *list;

	list = ft_create_elem_v(data);
	list->next = *begin_list;
	*begin_list = list;
}

int	ft_list_size_v(values_list *begin_list)
{
	values_list	*list;
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

void	v_list_clear(values_list **begin_list)
{
	values_list	*temp;
	values_list	*list;

	list = *begin_list;
	temp = list->next;
	free(list);
	*begin_list = temp;
}
