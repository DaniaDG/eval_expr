#include "eval.h"

int op_priority(char op)
{
	if (op == '+' || op == '-')
		return (1);
	if (op == '*' || op == '/' || op == '%')
		return (2);
	return (0);
}

int apply_op(int val1, int val2, char op)
{
	if (op == '+')
		return (val1 + val2);
	if (op == '-')
		return (val1 - val2);
	if (op == '*')
		return (val1 * val2);
	if (op == '/')
		return (val1 / val2);
	if (op == '%')
		return (val1 % val2);
	return (0);
}

