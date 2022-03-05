#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void showbit (void *vp, size_t size);

int main (void)
{
	char s[32];
	double	d;
	float	f;

	while (1)
	{
		s[read(0, s, 32)] = '\0';
		d = atof(s);
		f = d;
		write(1, "double:\t" ,9); showbit(&d, sizeof(double)); write(1, "\n" ,1);
		write(1, "float:\t" ,8); showbit(&d, sizeof(float)); write(1, "\n" ,1);
	}
}

void showbit (void *vp, size_t size)
{
	unsigned char	*p;
	char	*num = "0123456789ABCDEF";

	p = vp;
	while (size > 0)
	{
		write(1, num + (*p / 16), 1);
		write(1, num + (*p % 16), 1);
		write(1, " ", 1);
		p++;
		size--;
	}
	return ;
}
