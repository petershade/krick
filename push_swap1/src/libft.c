#include "push_swap.h"

void	my_putchar(char c) //функция посимвольного вывода
{
	if (c != 0)
		write(1, &c, 1);
}

void	my_putstr(char *str) //функция вывода строки
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			my_putchar(str[i]);
			i = i + 1;
		}
	}
}

void my_put_nbr(int i)
{
	if (i < 0)
	{
		my_putchar('-');
		i = -i;
	}
	if (i > 9)
	{
		my_put_nbr(i / 10);
		my_put_nbr(i % 10);
	}
	else
		my_putchar(i + 48);
}

static int my_strlen(char *c, int *is_letter) //считывает длину значения без минуса и ставит 1 во флаг с минусом, если число отрицательное
{
	int i;

	i = 0;
	if (c == NULL)
		return (0);
	while (c[i])
	{
		if (c[i] < '0' || c[i] > '9')
			if (c[i] != '-')
				*is_letter = 1;
			i = i + 1;
	}
	return (i);
}

int my_getnbr(char *str, int *numneg, int *is_letter) //переделывает число из чар в инт и ставит флаг 1, если число отрицательное
{
	int i;		//счетчик
	int out;	//число
	int pow;	//степень

	pow = 1;
	out = 0;
	i = my_strlen(str, is_letter) - 1; //убирает /n
	while (i >= 0)
	{
		if (str[i] == '-')	//если встречается '-' то ставится флаг 1 в отрицательное число и число становится отрицательным
			{
			out = -out;
			*numneg = *numneg + 1;
			}
		else	//иначе переводится в инт как в атои
		{
			out = out + ((str[i] - '0') * pow);
			pow = pow * 10;
		}
		i = i - 1;
	}
	return (out);
}