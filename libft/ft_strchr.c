#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	while ((*str != '\0') && (*str != (char)ch))
		str++;
	if (*str == (char)ch)
		return ((char *)str);
	return ((char *) NULL);
}
