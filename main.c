#include "eval.h"

int main(int argc, char **argv)
{
	int result;

	if (argc > 2 || argc == 1)
		return (0);
	result = evaluate(argv[1]);
	printf("Result = %d\n", result);
	return (0);
}
