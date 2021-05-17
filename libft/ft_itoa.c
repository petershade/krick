#include "libft.h"

static char	*ft_plus_int(int n, int len)
{
	char	*ss;

	ss = (char *)malloc(sizeof(*ss) * (len + 1));
	if (ss)
	{
		ss[len] = '\0';
		len--;
		while (len >= 0)
		{
			ss[len] = ((n % 10) + '0');
			n = n / 10;
			len--;
		}
		return (ss);
	}
	return (NULL);
}

static char	*ft_mius_int(int n, int len)
{
	char	*ss;

	ss = (char *)malloc(sizeof(*ss) * (len + 2));
	if (ss)
	{
		len++;
		ss[len] = '\0';
		len--;
		ss[0] = '-';
		while (len > 0)
		{
			ss[len] = ((n % 10) + '0');
			n = n / 10;
			len--;
		}
		return (ss);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*ss;
	int		len;
	int		num;

	len = 0;
	num = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		++len;
	}
	if (num >= 0)
		return (ss = ft_plus_int(num, len));
	return (ss = ft_mius_int((num * -1), len));
}
