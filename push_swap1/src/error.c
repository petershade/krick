#include "push_swap.h"

void my_putchar_error(char c) //выводит символы
{
	if (c != 0)
		write(1, &c, 1);
}

int	my_putstr_error(char *c) //возвращает 84 для ошибки и выводит ошибку
{
	int i;

	i = 0;
	if (c[i])
	{
		while (c[i])
		{
			my_putchar_error(c[i]);
			i = i + 1;
		}
	}
	return (84);
}

int error_msg(t_element *a, int is_letter, int num) //обрабатывает ошибки
{
	if (num < 2) //если меньше 2-х чисел
		return (my_putstr_error("./push_swap [num1] [num2] ... (more than one number)\n"));
	if (is_letter == 1) //если встречаются не числовые значения
		return (my_putstr_error("./push_swap [num1] [num2] ... (only numeric values)\n"));
	if (is_sort(a) != 0) //если список уже отсортирован
		return (my_putstr_error("List sorted\n"));
	return (0);
}