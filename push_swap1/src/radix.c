// static void	radix_first_loop(t_element	**a, t_element	**b, int i, int *len_x)
// {
// 	int j; //счетчик чисел

// 	j = 0;
// 	while (j < len_x[0]) //пока индекс меньше количества чисел проходимся по всему стэку
// 	{
// 		if (((*a)->val >> i & 1) == 0) //мы смотрим последнее число т.к побитовый сдвиг направлен вправо, если число равняется 0, то
// 		{
// 			pa(b, a, "pb "); //верхнее число стека А идёт на вершину В
// 			len_x[0] = len_x[0] - 1;
// 			len_x[1] = len_x[1] + 1;
// 		}
// 		else
// 		{
// 			*a = ra(*a, "ra "); //сдвигает вверх все элементы стека А на 1
// 			j = J + 1;
// 		}
// 	}
// }

// static void radix_second_loop(t_element **a, t_element **b, int i, int *len_x)
// {
// 	int j;

// 	j = 0;
// 	while (j < len_x[1])
// 	{
// 		if (((*b)->val >> i & 1) == 1)
// 		{
// 			pa(a, b, "pa ") //верхнее число стека B идёт на вершину A
// 			len_x[1] = len_x[1] - 1;
// 			len_x[0] = len_x[0] + 1;
// 		}
// 		else
// 		{
// 			*b = ra(*b, "rb "); //сдвигает вверх все элементы стека В на 1
// 			j = j + 1;
// 		}
// 	}
// }

// void radix(t_element **a, t_element **b, int numneg) //побитовая сортировка
// {
// 	int i; //индекс
// 	int *len_x; //ссылка для длин стэков

// 	len_x = malloc(sizeof(int) * 2); //выделяем помять поl число
// 	if (len_x == NULL) //проверяем на ошибки
// 		return; //завершить если есть ошибки
// 	len_x[0] = len_elem(*a); //записываем количество чисел в стэке А
// 	len_x[1] = 0; //записываем количество чисел в стэке В
// 	i = 0;
// 	while (i < 31) //максимальное интовое число в двоичной системе - 31 единица
// 	{
// 		radix_first_loop(a, b, i, len_x); //отправляем стэк А и В, индекс, количество элементов в стэке
// 		radix_second_loop(a, b, i, len_x); //отправляем стэк А и В, индекс, количество элементов в стэке
// 		i = i + 1;
// 	}
// }