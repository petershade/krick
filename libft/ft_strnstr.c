#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;
	char	*copy;

	i = 0;
	copy = (char *)str1;
	n_len = ft_strlen(str2);
	if (n_len == 0 || str1 == str2)
		return (copy);
	while (copy[i] != '\0' && i < len)
	{
		j = 0;
		while (copy[i + j] != '\0' && str2[j] != '\0' \
			&& copy[i + j] == str2[j] && i + j < len)
			j++;
		if (j == n_len)
			return (copy + i);
		i++;
	}
	return (0);
}
