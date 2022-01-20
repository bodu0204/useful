
#include <stdio.h>

void	test(int a, ...)
{
	printf ("*((int *)&a) = %d, *(((int *)&a) + 2) = %d, *(((int *)&a) + 4) = %d, *(((int *)&a) + 6) = %d, *(((int *)&a)+ 8) = %d, *(((int *)&a) + 10) = %d\n", *((int *)&a), *(((int *)&a) + 2), *(((int *)&a) + 4), *(((int *)&a) + 6), *(((int *)&a) + 8), *(((int *)&a) + 10));
}

int	main(void)
{
	test(1, 2, 3, 4, 5, 6);
	return (0);
}
