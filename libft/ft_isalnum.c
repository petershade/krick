#include "libft.h"

int	ft_isalnum(int	ch)
{
	if ((ch >= '0') && (ch <= '9'))
		return (1);
	else if ((ch >= 'A') && (ch <= 'Z'))
		return (1);
	else if ((ch >= 'a') && (ch <= 'z'))
		return (1);
	else
		return (0);
}
