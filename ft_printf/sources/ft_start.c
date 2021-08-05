#include "sources/ft_printf.h"

static int	ft_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(unsigned int num)
{
	int		len;
	char	*str;

	len = ft_len(num);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	str[0] = '0';
	if (num < 0)
		str[0] = '-';
	while (len)
	{
		if (num < 0)
			str[len--] = -(num % 10) + '0';
		else
			str[len--] = (num % 10) + '0';
		num /= 10;
	}
	if (num > 0)
		str[len] = num + '0';
	return (str);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strdup(const char *string)
{
	char	*str;
	size_t	i;

	str = malloc(ft_strlen(string) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (string[i])
	{
		str[i] = string[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	print_point(char *str, int len, t_flags *flags, unsigned long nb)
{
	if (flags->precision > len)
		len = pre_point(str, len, flags, nb);
	else if (flags->width == 0)
	{
		ft_putstr("0x");
		len += 2;
		if (flags->precision != 0)
			ft_putstr(str);
	}
	else if (flags->width)
		len = wid_point(str, len, flags);
	return (len);
}
