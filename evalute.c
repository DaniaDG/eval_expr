#include "eval.h"

void	push_and_pop(values_list **v_stack, operators_list **o_stack)
{
	int val1;
	int val2;
	char op;

	val2 = (*v_stack)->data;
	v_list_clear(v_stack);
	val1 = (*v_stack)->data;
	v_list_clear(v_stack);
	op = (*o_stack)->data;
	o_list_clear(o_stack);
	v_list_push_front(v_stack, apply_op(val1, val2, op));
}	

int evaluate(char *str)
{
	int k;
	values_list *v_stack = NULL;
	operators_list *o_stack = NULL;

	k = 0;
	while (str[k] != '\0')
	{
		if(str[k] == ' ')
			k++;
		else if(str[k] == '(')
		{
			o_list_push_front(&o_stack, str[k]);
			k++;
		}
		else if(str[k] >= '0' && str[k] <= '9')
		{
			v_list_push_front(&v_stack, atoi(str + k));
			while (str[k] != ' ' && str[k] != ')' && str[k] != '\0')
				k++;
		}
		else if(str[k] == ')')
		{
			while(ft_list_size_o(o_stack) != 0 && o_stack->data != '(')
				push_and_pop(&v_stack, &o_stack);    
			o_list_clear(&o_stack);
			k++;
		}
		else
		{
			while(ft_list_size_o(o_stack) != 0 && op_priority(o_stack->data) >= op_priority(str[k]))
				push_and_pop(&v_stack, &o_stack);    
			o_list_push_front(&o_stack, str[k]);
			k++;
		}
	}
	while(ft_list_size_o(o_stack) != 0)
		push_and_pop(&v_stack, &o_stack);
	return (v_stack->data);
}
