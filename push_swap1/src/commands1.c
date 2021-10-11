#include "push_swap.h"

t_element	*rra(t_element *a, char *letter) //сдвигает вниз все элементы стека a на 1
{
	if (a == NULL) //обрабатываем ошибки
		return (NULL);
	if (len_elem(a) <= 1) //если длина списка меньше 2, то возвращаем список
		return (a);
	my_putstr(letter);
	return (a->prev); //последний элемент стаёт первым из-за чего все элементы сдвигаются на 1 вниз
}

int ss(t_element **a, t_element **b) //sa + sb
{
	my_putstr("ss");
	*a = sa(*a, "x");
	*b = sa(*b, "x");
	return (1);
}

int rr(t_element **a, t_element **b) //ra + rb
{
	my_putstr("rr");
	*a = ra(*a, "x");
	*b = ra(*b, "x");
	return (1);
}

int rrr(t_element **a, t_element **b) //rra + rrb
{
	my_putstr("rrr");
	*a = rra(*a, "x");
	*b = rra(*b, "x");
	return (1);
}