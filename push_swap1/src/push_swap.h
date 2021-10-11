#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_element
{
	int 	val;				//значение
	struct	s_element *next;	//ссылка на следующий элемент
	struct 	s_element *prev;	//ссылка на предыдущий элемент
}			t_element;

long double	calc_median(t_element *a, int n);
void 		quicksort(int n, t_element **a, t_element **b);
int 		len_elem(t_element *list);
int 		is_sort(t_element *a);
void		my_putchar(char c);
void		my_putstr(char *str);
void 		my_put_nbr(int i);
void 		my_putchar_error(char c);
int			my_putstr_error(char *c);
int 		error_msg(t_element *a, int is_letter, int num);
t_element	*create_list(int val);
t_element	*add_top(t_element *next, int val);
t_element 	*delete_top(t_element *list);
int 		my_getnbr(char *str, int *numneg, int *is_letter);
t_element	*arg_to_list(char **arg, int num, int *numneg, int *is_letter);
t_element	*sa(t_element *list, char *letter);
int 		pa(t_element **a, t_element **b, char *letter);
t_element	*ra(t_element *a, char *letter);
t_element	*rra(t_element *a, char *letter);
int 		ss(t_element **a, t_element **b);
int 		rr(t_element **a, t_element **b);
int 		rrr(t_element **a, t_element **b);
int 		quick_high_to_b(t_element **a, t_element **b, int n);
void 		quick_to_init_a(int top_half_len, t_element **a);
void 		guick_high_to_a(t_element **a, t_element **b, int top_half_len);
void 		quick_smtof(t_element **a, int top_half_len);
void 		quick_smtob(t_element **a, int top_half_len);

#endif