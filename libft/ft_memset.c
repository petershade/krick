#include "libft.h"

void	*ft_memset(void *dst, char c, size_t n)
{
	int		i;
	char	*p;

	i = 1;
	p = (char *) dst;
	while (n-- > 0)
		*p++ = c;
	return (dst);
}
