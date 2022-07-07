#include "debug.h"
void	getstack(int i);

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (i < 1)
		i = atoi(argv[1]);
	getstack(i);
	return (0);
}

void	getstack(int i)
{
	int	stack[i];

	printf("i = %d\n", i);
	printf("sizeof(stack) = %zu\n", sizeof(stack));
	return ;
}
