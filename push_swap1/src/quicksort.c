#include "push_swap.h"

int quick_high_to_b(t_element **a, t_element **b, int n) //числа меньше медианы переносятся в стэк Б
{
	int 		i; //счётчик
	int 		top_half_len; //верхняя половина стэка
	long double	median; //середина упорядоченного ряда
	long double	a_val; //значение стэка А

	median = calc_median(*a, n); //ищем среднее число
	top_half_len = 0; //инициализируем значения
	i = 0;
	while (i < n) //пока индекс меньше количества чисел
	{
		a_val = (long double) (*a)->val; //узнаем значение листа
		if (*a != NULL && a_val <= median) //если число меньше медианы, то верхнее число стека А идёт на вершину Б
		{
			pa(b, a, "pb\n");
			top_half_len = top_half_len + 1;
		}
		else //иначе сдвигает вверх все элементы стека А на 1
			*a = ra(*a, "ra\n");
		i = i + 1;
	}
	return (top_half_len);
}

void quick_to_init_a(int top_half_len, t_element **a)
{
	int temp; //временное хранилище файла

	temp = 0; //инициализируем переменную
	while (temp < top_half_len) //пока темп меньше количества чисел больших медианы увеличиваем на 1
	{
		*a = rra(*a, "rra\n"); //сдвигаем вниз все элементы стека А на 1
		temp = temp + 1;
	}
}

void guick_high_to_a(t_element **a, t_element **b, int top_half_len) //переносим все числа из стэка В в А
{
	int temp; //временное хранилище файла

	temp = 0; //инициализируем переменную
	while (temp < top_half_len)
	{
		pa(a, b, "pa\n"); //верхнее число стека B идёт на вершину A
		temp = temp + 1;
	}
}

void quick_smtof(t_element **a, int top_half_len)
{
	int temp; //временное хранилище

	temp = 0; //инициализируем временное хранилище
	while (temp < top_half_len) //пока темп меньше чем числа меньшие медианы
	{
		*a = ra(*a, "ra\n"); //сдвигаем вверх все элементы стека А на 1
		temp = temp + 1;
	}
}

void quick_smtob(t_element **a, int top_half_len)
{
	int temp; //временное хранилище

	temp = 0; //инициализируем временное хранилище
	while (temp < top_half_len) //пока темп меньше чем числа большие медианы
	{
		*a = rra(*a, "rra\n"); //сдвигаем вниз все элементы стека a на 1
		temp = temp + 1;
	}
}