#include "sources/ft_printf.h"

static int	neg_prec_neg(t_flags *flags, int len_di, int len, char *str)
{
	if ((flags->width > len_di + 1) && flags->minus == 0)
	{
		if (!flags->zero && (flags->width - len_di - 1) > 0)
		{
			len += ft_print_width(flags->width - len_di - 1, 0);
			ft_putchar('-', 1);
		}
		else if ((flags->width - len_di - 1) > 0)
		{
			ft_putchar('-', 1);
			len += ft_print_width(flags->width - len_di - 1, 1);
		}
		ft_putstr(str);
	}
	else
	{
		ft_putchar('-', 1);
		ft_putstr(str);
		if (flags->width > len_di && flags->minus == 1
			&& (flags->width - len_di - 1) > 0)
			len += ft_print_width(flags->width - len_di - 1, 0);
	}
	return (len + 1);
}

static int	neg_prec_pol(t_flags *flags, int len_di, int len, char *str)
{
	if (flags->width > flags->precision && flags->minus == 0)
	{
		if (flags->precision > len_di)
			len += ft_print_width(flags->width - flags->precision - 1, 0);
		else if (flags->width - len_di - 1 > 0)
			len += ft_print_width(flags->width - len_di - 1, 0);
	}
	ft_putchar('-', 1);
	if (flags->precision > len_di)
		len += ft_print_width(flags->precision - len_di, 1);
	ft_putstr(str);
	if (flags->width > flags->precision && flags->minus == 1)
	{
		if (flags->precision > len_di)
			len += ft_print_width(flags->width - flags->precision - 1, 0);
		else if (flags->width - len_di - 1 > 0)
			len += ft_print_width(flags->width - len_di - 1, 0);
	}
	return (len + 1);
}

int	print_neg_di(int n, t_flags *flags)
{
	char			*str;
	int				len_di;
	int				len;
	unsigned int	m;

	len = 0;
	m = (unsigned int) - n;
	str = ft_itoa(m);
	len_di = ft_strlen(str);
	if (flags->precision == -1)
		len = neg_prec_neg(flags, len_di, len, str);
	else if (flags->precision >= 0)
		len = neg_prec_pol(flags, len_di, len, str);
	free(str);
	return (len + len_di);
}
