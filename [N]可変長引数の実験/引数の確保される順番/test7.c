
#include <stdio.h>

void	test(int a, ...)
{
	size_t	i;
	void	*p;

	p = &a;
	i = 0;
	p -= 180;
	printf ("\np == &a (== %p)\n", p);
	while (i < 180)
	{
		printf("*((int *)(p - %zu (==%8p))) == %d\n", 180 - i, ((int *)(p + i)), *((int *)(p + i)));
		i++;
	}
	p = &a;
	printf ("\np == &a (== %p)\n", p);
	i = 0;
	while (i < 120)
	{
		printf("*((int *)(p + %zu (==%8p))) == %d\n", i, ((int *)(p + i)), *((int *)(p + i)));
		i++;
	}
	#ifdef __CDECL
	printf("yes\n");
	#endif
	return ;
}

int	main(void)
{
	test(1, 2, 3, 4, 5, 6, 7, 8);
	return (0);
}
