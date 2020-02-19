// A + B
// https://www.acmicpc.net/problem/1000
#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int num)
{
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + '0');
}

int main(void)
{
	char str[3];
	int sum = 0;

	read(0, str, 3);
	sum = (str[0] - '0') + (str[2] - '0');
	ft_putnbr(sum);
}
/*
	read
	https://www.it-note.kr/201
*/