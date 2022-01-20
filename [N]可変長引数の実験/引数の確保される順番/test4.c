
#include <stdio.h>

void	test(int a, ...)
{
	printf ("*((int *)&a) = %d, *(((int *)&a) + 1) = %d, *(((int *)&a) + 2) = %d, *(((int *)&a) + 3) = %d, *(((int *)&a)+ 4) = %d, *(((int *)&a) + 5) = %d\n", *((int *)&a), *(((int *)&a) + 1), *(((int *)&a) + 2), *(((int *)&a) + 3), *(((int *)&a) + 4), *(((int *)&a) + 5));
}

int	main(void)
{
	test(1, 2, 3, 4, 5, 6);
	return (0);
}
