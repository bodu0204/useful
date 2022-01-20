#include <stdio.h>
#include <string.h>
int main (void)
{
	char	c;
	short	s;
	int		i;
	long	l;
	char	str[32];

	(void)c;
	(void)s;
	(void)i;
	(void)l;
	(void)str;
	c = 0;
	s = 0;
	i = 0;
	l = 0;
	strcpy(str, "hello");
	printf("&c = %hhn.\n", &c);
	printf("&s = %hn.\n", &s);
	printf("&i = %n.\n", &i);
	printf("&l = %ln.\n", &l);
	printf("str = %hhn\n", str);
	return (0);
}
