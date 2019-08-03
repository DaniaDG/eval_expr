#ifndef EVAL_H
# define EVAL_H

# include <stdlib.h>
# include <stdio.h> //for printf

typedef struct		v_list
{
	struct v_list	*next;
	int             data;
}			values_list;

typedef struct		o_list
{
	struct o_list	*next;
	char            data;
}			operators_list;

values_list	*ft_create_elem_v(int data);
operators_list	*ft_create_elem_o(char data);
void	v_list_push_front(values_list **begin_list, int data);
void	o_list_push_front(operators_list **begin_list, char data);
int	ft_list_size_v(values_list *begin_list);
int	ft_list_size_o(operators_list *begin_list);
void	v_list_clear(values_list **begin_list);
void	o_list_clear(operators_list **begin_list);
int op_priority(char op);
int apply_op(int val1, int val2, char op);
int evaluate(char *str);

#endif
