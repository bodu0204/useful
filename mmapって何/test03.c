#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
	char	*content;
	char	str[1024];

	write(1, "\n", 1);
	content = mmap(0, 1024, PROT_READ | PROT_WRITE, MAP_PRIVATE, 0, 0);
	printf("content = %p\n", content);
	memcpy(str, content, 1024);
	printf("str = %s\n", str);
	return (0);
}
