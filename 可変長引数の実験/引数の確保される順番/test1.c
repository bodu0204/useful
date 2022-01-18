
#include <stdio.h>

void	test(int a, int b, int c)
{
	printf ("&a = %p, &b = %p, &c = %p", &a, &b, &c);
}

int	main(void)
{
	test(0, 0, 0);
	return (0);
}
