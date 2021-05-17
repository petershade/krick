#include "libft.h"

int	ft_toupper(int	sym)
{
	if (sym >= 'a' && sym <= 'z')
		sym -= 32;
	return (sym);
}
