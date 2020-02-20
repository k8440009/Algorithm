// A - B
// https://www.acmicpc.net/problem/1001
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int num)
{
	if (num < 0)
	{
		ft_putchar('-');
		ft_putnbr(num * (-1));
	}
	else if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + '0');
}

void ft_solve(int a, int b)
{
	int result = a - b;
	ft_putnbr(result);
}

int main()
{
	char str[3];
	read(0, str, 3);
	ft_solve(str[0] - '0', str[2] - '0');
}