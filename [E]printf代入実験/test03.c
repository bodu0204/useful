#include <stdio.h>
#include <string.h>
#include <limits.h>
int main (void)
{
	long i = -891234;
	(void)i;
	printf("%%f = %f/\n", 0.0);
	printf("%%f = %f/\n", 1.0);
	printf("%%f = %f/\n", 0.1);
	printf("%%f = %f/\n", 0.123456489);
	printf("%%f = %f/\n", 54321.123456489);
	printf("%%d = %#10.6x/\n", i);
	return (0);
}
