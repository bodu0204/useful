#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
	int		fd;
	char	*content;
	char	str[32];
	size_t	size;

	fd = open("sumpletxt02.txt",O_RDWR);
	content = mmap(0, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	printf("content = %p\n", content);
	size = 0;
	while (1)
	{
		if(read(0, str, 32) > 1)
		{
			close(fd);
			return (0);
		}
		size += 32;
		memcpy(content + size, "\t\tI wrote something now", 23);
		printf("[sart\\n]\n%s[end]\n",content);
	}

}
