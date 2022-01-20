
#include <stdio.h>

void	test(int a, int b, int c, int d, int e, int f, int g, int h)
{
	printf ("&a = %ld, &b = %ld, &c = %ld, &d = %ld, &e = %ld, &f = %ld, &g = %ld, &h = %ld\n", (unsigned long)&a, (unsigned long)&b, (unsigned long)&c, (unsigned long)&d, (unsigned long)&e, (unsigned long)&f, (unsigned long)&g, (unsigned long)&h);
}

int	main(void)
{
	test(0, 0, 0, 0, 0, 0, 0, 0);
	return (0);
}
