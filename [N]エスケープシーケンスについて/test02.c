#include <unistd.h>
#include <stdio.h>
int main (void)
{
	printf("\033[2J");
	unsigned long	i;
	i = 0;
	while (1)
	{
		printf("\033[2J");
		i++;
		sleep(1);
		printf("%lutimes\n",i);
	}
	return (0);
}
