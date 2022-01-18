#include <stdio.h>
#include <string.h>
int main (void)
{
	unsigned int	i;
	unsigned long	l;

	(void)i;
	(void)l;
	i = ~0L;
	l = ~0L;
	printf("(int)%%hhu = %hhu.\n", i);
	printf("(int)%%hu = %hu.\n", i);
	printf("(int)%%u = %u.\n", i);
	printf("(int)%%lu = %lu.\n", i);
	printf("(int)%%llu = %llu.\n", i);
	printf("(int)%%qu = %qu.\n", i);
	printf("(int)%%Lu = %Lu.\n", i);
	printf("(int)%%ju = %ju.\n", i);
	printf("(int)%%zu = %zu.\n", i);
	printf("(int)%%tu = %tu.\n", i);
	printf("(long)%%hhu = %hhu.\n", l);
	printf("(long)%%hu = %hu.\n", l);
	printf("(long)%%u = %u.\n", l);
	printf("(long)%%lu = %lu.\n", l);
	printf("(long)%%llu = %llu.\n", l);
	printf("(long)%%qu = %qu.\n", l);
	printf("(long)%%Lu = %Lu.\n", l);
	printf("(long)%%ju = %ju.\n", l);
	printf("(long)%%zu = %zu.\n", l);
	printf("(long)%%tu = %tu.\n", l);
	return (0);
}
