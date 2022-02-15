#include <unistd.h>
#include <stdio.h>
int main (void)
{
	unsigned long	i;
	unsigned long	ii;
	i = 0;
	ii = 0;
	printf("\n\n\n\n\n\n\n\n\n\n");//* dw 10 */
	while (1)
	{
		i++;
		if (i >= 60)
		{
			ii++;
			i = 0;
		}
		sleep(1);
		printf("\033[2K");/* clear line */
		printf("%lum",ii);
		printf("\033[%dA" ,10);/* up 10 */
		printf("\033[2K");/* clear line */
		printf("\033[%dD" ,10); //カーソルを10行だけ左に移動
		printf("%lus",i);
		printf("\n\n\n\n\n\n\n\n\n\n");//* dw 10 */
		fflush(stdout);
	}
	return (0);
}
