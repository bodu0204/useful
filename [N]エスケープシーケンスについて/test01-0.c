#include <unistd.h>
int main (void)
{
	write(1, "\033[2J", 1);
	return (0);
}
