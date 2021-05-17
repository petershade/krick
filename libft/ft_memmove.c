#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*s;
	const unsigned char	*d;

	if (!dst && !src)
		return (NULL);
	s = (unsigned char *)dst;
	d = (unsigned char *)src;
	i = 0;
	if (d < s)
		while (++i <= n)
			s[n - i] = d[n - i];
	else
		while (n-- > 0)
			*(s++) = *(d++);
	return (dst);
}
