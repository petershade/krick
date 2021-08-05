#include "sources/ft_printf.h"

static int	neg_precision_pos(t_flags *flags, int len_di, int len, char *str)
{
	if (flags->width > len_di && flags->minus == 0)
	{
		if (!flags->zero)
			len += ft_print_width(flags->width - len_di, 0);
		else if (flags->width > len_di)
			len += ft_print_width(flags->width - len_di, 1);
	}
	ft_putstr(str);
	if (flags->width > len_di && flags->minus == 1)
		len += ft_print_width(flags->width - len_di, 0);
	return (len);
}

static int	pos_precision_pol(t_flags *flags, int len_di, int len, char *str)
{
	if (flags->width > flags->precision && flags->minus == 0)
	{
		if (flags->precision > len_di)
			len += ft_print_width(flags->width - flags->precision, 0);
		else if (flags->width > len_di)
			len += ft_print_width(flags->width - len_di, 0);
	}
	if (flags->precision > len_di)
		len += ft_print_width(flags->precision - len_di, 1);
	ft_putstr(str);
	if (flags->width > flags->precision && flags->minus == 1)
	{
		if (flags->precision > len_di)
			len += ft_print_width(flags->width - flags->precision, 0);
		else if (flags->width > len_di)
			len += ft_print_width(flags->width - len_di, 0);
	}
	return (len);
}

int	print_pos_di(int num, t_flags *flags)
{
	char	*str;
	int		len;
	int		len_di;

	len = 0;
	if (num == 0 && flags->precision == 0)
	{
		len = ft_print_width(flags->width, 0);
		return (len);
	}
	str = ft_itoa(num);
	len_di = ft_strlen(str);
	if (flags->precision == -1)
		len = neg_precision_pos(flags, len_di, len, str);
	else if (flags->precision >= 0)
		len = pos_precision_pol(flags, len_di, len, str);
	free(str);
	return (len + len_di);
}

int	print_di(int num, t_flags *flags)
{
	int	len;

	len = 0;
	if (num >= 0)
		len = print_pos_di(num, flags);
	else
		len = print_neg_di(num, flags);
	return (len);
}
