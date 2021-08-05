#include "sources/ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnstr(char *str, int num)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (i < num)
		write(1, &str[i++], 1);
}

int	print_s(char *str, t_flags *flags)
{
	int	len;
	int	len_str;

	if (!str)
		str = "(null)";
	len = 0;
	len_str = ft_strlen(str);
	if (flags->precision >= 0)
	{
		if (len_str > flags->precision)
			len_str = flags->precision;
	}
	if (flags->minus)
		ft_putnstr(str, len_str);
	if (flags->width > len_str)
	{
		if (flags->zero)
			len = ft_print_width((flags->width - len_str), 1);
		else
			len = ft_print_width(flags->width - len_str, 0);
	}
	if (flags->minus == 0)
		ft_putnstr(str, len_str);
	return (len + len_str);
}
