#include "libft.h"

int	ft_memcmp (const void *arr1, const void *arr2, size_t n)
{
	size_t			i;
	unsigned char	*aarr1;
	unsigned char	*aarr2;

	i = 0;
	aarr1 = (unsigned char *)(arr1);
	aarr2 = (unsigned char *)(arr2);
	while (i < n)
	{
		if (aarr1[i] != aarr2[i])
			return (aarr1[i] - aarr2[i]);
		i++;
	}
	return (0);
}
