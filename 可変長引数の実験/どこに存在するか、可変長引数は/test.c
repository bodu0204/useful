#include <stdio.h>
#include <stdarg.h>
#include <string.h>

typedef struct s{
	char	content[24];
}vatest;

void	showbit(void *s);
void	son(char *s, ...);
int		g_i;
char	*g_s;
va_list	g_ap;

void	test(char *s, ...)
{
	va_list		ap;
	vatest		new;

	g_s = s;
	printf("%s(%p)\n", s, s);
	va_start(ap, s);
	showbit(&ap);
	memcpy(&g_ap, &ap, 24);
	showbit(&g_ap);
	son("hello", "I'm testing...");
	return ;
}

void son(char *s, ...)
{
	printf("son--------------------------------------\n");
	printf("%s(%p)\n", g_s, g_s);
	g_s = va_arg(g_ap, char *);
	printf("%s(%p)\n", g_s, g_s);
	g_i = va_arg(g_ap, int);
	printf("%d\n", g_i);
	g_s = va_arg(g_ap, char *);
	printf("%s(%p)\n", g_s, g_s);
	g_s = va_arg(g_ap, char *);
	printf("%s(%p)\n", g_s, g_s);
	printf("son--------------------------------------\n");
}

int	main(void)
{
	test("hello", "world", 42, "Can I do this ?");
	/* long a = 324678325763255;
	long b = 2354365487867564;
	long c = 3254363334567;
	long d = 7656345; */
	/* printf("main-------------------------------------\n");
	g_s = va_arg(g_ap, char *);
	printf("%s(%p)\n", g_s, g_s);
	g_i = va_arg(g_ap, int);
	printf("%d\n", g_i);
	g_s = va_arg(g_ap, char *);
	printf("%s(%p)\n", g_s, g_s);
	g_s = va_arg(g_ap, char *);
	printf("%s(%p)\n", g_s, g_s);
	g_s = va_arg(g_ap, char *);
	printf("%s(%p)\n", g_s, g_s);
	printf("main-------------------------------------\n"); */
	return (0);
}

void showbit(void *s)
{
	size_t i;
	size_t ii;
	size_t m;
	unsigned char c;
	unsigned char ic;
	size_t line;

	line = 16;
	m = 0;
	ii = 0;
	printf("\nstart:%p\n", s);
	while (m < 3)
	{
		printf("");
		i = 0;
		while (i < line)
		{
			printf("%8zu", ii + i + 1);
			i++;
		}
		printf("\n");
		i = 0;
		while (i < line)
		{
			if (*((unsigned char *)s + ii + i) == 0 && !m)
				m++;
			ic = 1 << 7;
			c = *((unsigned char *)s + ii + i);
			while (ic > 0)
			{
				printf("%d", c / ic);
				c %= ic;
				ic = ic >> 1;
			}
			i++;
		}
		printf("\n");
		if (m > 0)
			m++;
		ii += line;
	}

}
