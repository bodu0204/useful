
#include <stdio.h>

void	test(int a, int b, int c, int d, int e, int f, int g, int h)
{
	printf ("&a = %p, &b = %p, &c = %p, &d = %p, &e = %p, &f = %p, &g = %p, &h = %p\n", &a, &b, &c, &d, &e, &f, &g, &h);
}

int	main(void)
{
	test(0, 0, 0, 0, 0, 0, 0, 0);
	return (0);
}
