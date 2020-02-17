#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, sizeof(char));
}

void ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int main()
{
	ft_putstr("강한친구 대한육군\n강한친구 대한육군");
}