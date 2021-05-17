#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (!s || len <= 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	{
		i = ft_strlen(&s[start]);
		if (i < len)
			len = i;
		str = malloc((len + 1) * sizeof(char));
		if (!(str))
			return (NULL);
		i = start;
		while (s[i] && (i - start) < len)
		{
			str[i - start] = s[i];
			i++;
		}
		str[i - start] = '\0';
		return (str);
	}
}
