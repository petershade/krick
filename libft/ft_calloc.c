#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*pointer;

	pointer = malloc(size * count);
	if (!pointer)
		return (NULL);
	ft_memset(pointer, 0, count * size);
	return (pointer);
}
