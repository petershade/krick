#include "push_swap.h"

long double	calc_median(t_element *a, int n) //калькулятор медианы
{
	t_element	*temp; //временный файл
	long double	median; //середина упорядоченного ряда
	int 		i; //счётчик
	long double	n_long; //количество чисел

	i = 0; //инициализируем переменные
	temp = a;
	median = 0;
	n_long = (long double) n;
	while (i < n) //пока индекс меньше количества всех чисел считаем
	{
		median = median + temp->val; //складываем все числа
		temp = temp->next;
		i = i + 1;
	}
	if (median == 0 || n == 0) //проверяем на ошибки
		return (0);
		// return (median / n_long);
	else
		return (median / n_long);
		// return (0); //возвращаем сумму всех чисел деленное на количество
}

void quicksort(int n, t_element **a, t_element **b) //сортировка чисел делением стэка на 2
{
	int	top_half_len;

	if (n <= 1)
		return;
	top_half_len = quick_high_to_b(a, b, n); //отправляем переменную с количеством чисел и 2 стэка, чтобы перекинуть числа меньше медианы в стэк В
	quick_to_init_a(n - top_half_len, a); //отправляем переменную с количеством чисел больше медианы и стэк А
	guick_high_to_a(a, b, top_half_len); //отправляем стэки А и Б, переменную с количеством чисел меньше медианы, чтобы перенести все числа из стэка В в А
	if (top_half_len == n || top_half_len == 0) //если количество чисел меньших медианы равно количеству всех чисел или 0, то завершаем
		return;
	quicksort(top_half_len, a, b); //создаем рекурсию для того чтобы отсортировать по порядку числа меньшие медианы
	quick_smtof(a, top_half_len); //перемещаем вниз все отсортированные числа сдвигая наверх каждое
	quicksort(n - top_half_len, a, b); //создаем рекурсию для того чтобы отсортировать по порядку числа большие медианы
	quick_smtob(a, top_half_len); //возвращаем на место отсортированные числа меньшие медианы
}

t_element	*arg_to_list(char **arg, int num, int *numneg, int *is_letter) //создает список и переводит в него значения аргументов
{
	t_element	*a;
	int 		to_put;

	a = NULL;
	if (num < 2)
		return (NULL);
	while (num > 1) //считываем числа
		{
		to_put = my_getnbr(arg[num - 1], numneg, is_letter);
		a = add_top(a, to_put); //переносим все значения в список
		num = num - 1; //переходим к следующему
		}
	return (a); //возвращаем список
}

int main(int num, char **arg)
{
	t_element	*a; //стек А
	t_element	*b; //стек Б
	int 		numneg; //негативное число
	int			is_letter; //флаг для минуса

	a = NULL; //инициализируем переменные и списки
	b = NULL;
	numneg = 0;
	is_letter = 0;
	a = arg_to_list(arg, num, &numneg, &is_letter); // переводим аргументы в список
	if (error_msg(a, is_letter, num) == 84) //обработка ошибок
		return (84);
	if (num <= 5000) //если чисел меньше 5000, то сортируем их с быстрой сортировкой(делением стэка на 2)
		 quicksort(len_elem(a), &a, &b); //отправляем количеству чисел и два стэка
	//else иначе сортируем побитовой сортировкой
	//	radix(&a, &b, numneg); //отправляем 2 стэка и количество негативных чисел
	my_putstr("rra ra\n");
	return (0);
}
