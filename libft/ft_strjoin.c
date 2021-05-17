#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	tlen;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tlen = len1 + len2 + 1;
	res = malloc(tlen + 1);
	if (res == 0)
		return (NULL);
	while (*s1)
		*(res++) = *(s1++);
	*res = 0;
	res -= len1;
	ft_strlcat(res, s2, tlen);
	return (res);
}
