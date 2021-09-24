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
}

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

t_element	*add_top(t_element *next, int val) //создает список в который заносит все значения из аргументов
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
	out->prev = next->prev; //записываем в новый элемент ссылку на самого себя тк теперь это начало
	next->prev->next = out;
	next->prev = out;
	return (out);
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

t_element	*arg_to_list(int argc, char **argv, int *numneg, int *is_letter)
{
	t_element	*a;
	int 		to_put;

	a = NULL;
	if (argc < 2)
		return (NULL);
	while (argc > 1) //считываем числа
	{
		to_put = my_getnbr(argv[argc - 1], numneg, is_letter);
		a = add_top(a, to_put); //переносим все значения в список
		argc = argc - 1; //переходим к следующему
	}
	return (a); //возвращаем список
}

int main(int num, char **argv)
{
	t_element	*a; //стек А
	t_element	*b; //стек Б
	int 		numneg; //негативное число
	int			is_letter; //флаг для минуса

	a = NULL; //инициализируем переменные и списки
	b = NULL;
	numneg = 0;
	is_letter = 0;
	a = arg_to_list(argc, argv, &numneg, &is_letter); // переводим аргументы в список
	if (error_msg(a, is_letter, num) == 84) //обработка ошибок
}