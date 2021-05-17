#include "libft.h"

char	*ft_strrchr(const char	*str, int	ch)
{
	size_t	len;

	len = ft_strlen(str);
	if ((char)ch == '\0')
		return ((char *)str + len);
	while (len--)
		if (*(str + len) == (char)ch)
			return ((char *)(str + len));
	return (NULL);
}
