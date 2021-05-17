#include "libft.h"

void	*ft_memchr(const void	*arr, int	c, size_t	n)
{
	size_t			i;
	unsigned char	*aarr;

	aarr = (unsigned char *)(arr);
	i = 0;
	if (n == 0 || (n + 1 < n))
		return (0);
	while (n != 0)
	{
		if (aarr[i] == (unsigned char)c)
			return ((void *)&(arr)[i]);
		i++;
		n--;
	}
	return (0);
}
