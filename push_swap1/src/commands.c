#include "push_swap.h"

t_element	*sa(t_element *list, char *letter) //меняет два верхних числа в стеке А
{
	t_element	*temp; //временное хранилище файла
	t_element	*out;

	if (len_elem(list) < 2) // если в стэке меньше 3 элементов то возвращаем лист
		return (list);
	my_putstr(letter); //
	out = list->next; //1-й элемент out равняется 2-му элементу
	temp = out; //temp равняется out
	out->next = list; //2-й элемент out равняется 1-му элементу
	out->prev = list->prev; //последний элемент out равняется последнему элементу list
	list->next = temp->next; //2-й элемент листа равняется 2-му элементу temp
	list->prev = out;
	return (out);
}
int pa(t_element **a, t_element **b, char *letter) //верхнее число стека B идёт на вершину A
{
	if (*b == NULL) //обрабатываем ошибки
		return (1);
	my_putstr(letter);
	*a = add_top(*a, (*b)->val); //добавляем элемент в список А и записываем в val число из стэка В
	*b = delete_top(*b); //удаляем первый элемент списка В
	return (1);
}

t_element	*ra(t_element *a, char *letter) //сдвигает вверх все элементы стека А на 1
{
	if (a == NULL) //обрабатываем ошибки
		return (NULL);
	if (len_elem(a) <= 1) //если длина списка меньше 2, то возвращаем список
		return (a);
	my_putstr(letter);
	return (a->next); //второй элемент стает перывм из-за чего все элементы сдвигаются на 1 навверх
}
