#include "push_swap.h"

int len_elem(t_element *list) //считает количество элементов в списке
{
	int 		i;
	t_element	*fin; //последний элемент(стоит в самом начале)

	if (list == NULL) //если список пуст заканчиваем)
		return (0);
	fin = list; //последний элемент равен ссылке на первый элемент
	list = list->next; //начинаем со второго элемента
	i = 1;
	while (list != fin) //пока не будет равен ссылке на первый элемент прибавляем 1
		{
		list = list->next;
		i = i + 1;
		}
	return (i);
}

int is_sort(t_element *a)
{
	t_element	*temp;
	t_element	*final;

	final = a;
	temp = a;
	if (len_elem(a) <= 1) //если в списке меньше 1 элемента возвращаем 1 и завершаем
		return (1);
	while ((temp->next)->next != final) //если следующее число больше предыдущего, то возвращаем 0 иначе 1. так мы поймем отсортирован ли массив
		{
		if (temp->val > (temp->next)->val)
			return (0);
		return (1);
		}
	if (temp->val > (temp->next)->val)
		return (0);
	return (1);
}

t_element	*create_list(int val) //создаем новый лист, записываем в него число, он же и будет являться ссылкой на первый и последний элемент
{
	t_element	*out;

	out = malloc(sizeof(t_element));
	if (out == NULL)
		return (NULL);
	out->val = val;
	out->next = out;
	out->prev = out;
	return(out);
}

t_element	*add_top(t_element *next, int val) //заносит числа из аргументов в листы списка
{
	t_element	*out;

	out = malloc(sizeof(t_element)); //выделяем память под лист
	if (out == NULL) //обрабатываем ошибку
		return (NULL);
	if (next == NULL)  //если список пуст, то вызываем функцию создания нового листа
		{
		free(out);
		return (create_list(val));
		}
	out->val = val; //записываем значение
	out->next = next; //записываем в новый элемент ссылку на список
	out->prev = next->prev; //в новый элемент записываем ссылку на начало списка тк теперь это первый элемент
	next->prev->next = out; //новый элемент становится началом списка
	next->prev = out; //первый элемент списка стает вторым
	return (out);
}

t_element *delete_top(t_element *list) //удаляет элемент из начала списка
{
	t_element	*next; //создаем новый элемент

	if (list->next == list) //если в списке единственный элемент, то удаляем
		next = NULL;
	else
	{
		next = list->next; //иначе новый элемент равняется 2-му
		list->prev->next = list->next; //последний элемент ссылается на наш новый созданный элемень
		list->next->prev = list->prev; //наш новый элемент ссылается на последний элемент
	}
	free(list); //чистим первый элемент
	return (next); //возвращаем новый список
}