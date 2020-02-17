
#include <unistd.h>

int main(void)
{
	const char *str = "Hello World!";
	write(1, str, 12);
}
