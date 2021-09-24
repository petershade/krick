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

int len_elem(t_element *list);
int is_sort(t_element *a);
void my_putchar_error(char c);
int	my_putstr_error(char *c);
int error_msg(t_element *a, int is_letter, int num);
t_element	*create_list(int val);
t_element	*add_top(t_element *next, int val);
int my_getnbr(char *str, int *numneg, int *is_letter);
t_element	*arg_to_list(int argc, char **argv, int *numneg, int *is_letter);

#endif