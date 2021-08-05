#include "sources/ft_printf.h"

static int	ft_len_po(unsigned long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static int	pri_ox(void)
{
	ft_putstr("0x");
	return (2);
}

int	pre_point(char *str, int len, t_flags *flags, unsigned long nb)
{
	if ((flags->precision > len && flags->precision < flags->width) \
	&& flags->minus == 0)
	{
		len += ft_print_width(flags->width - flags->precision - 2, 0);
		ft_putstr("0x");
		len += ft_print_width(flags->precision - len + 4, 1);
		len += 2;
		ft_putstr(str);
	}
	if (flags->precision > len)
	{
		len += pri_ox();
		len += ft_print_width(flags->precision - len + 2, 1);
		if (nb != 0)
			ft_putstr(str);
		if (flags->width - len > 0)
			len += ft_print_width(flags->width - len, 0);
	}
	return (len);
}

int	wid_point(char *str, int len, t_flags *flags)
{
	if (len < flags->width)
	{
		if ((flags->width - len > 2) && flags->minus == 0)
		{
			len += ft_print_width(flags->width - len - 2, 0);
			len += pri_ox();
			if (flags->precision != 0)
				ft_putstr(str);
		}
		else
		{
			len += pri_ox();
			if (flags->precision != 0)
				ft_putstr(str);
			if (flags->width - len > 0)
				len += ft_print_width(flags->width - len, 0);
		}
	}
	else
	{
		len += pri_ox();
		ft_putstr(str);
	}
	return (len);
}

int	print_p(unsigned long nb, t_flags *flags)
{
	char	*str;
	int		len;
	int		len_po;

	len = 1;
	if (flags->precision == -1 && nb == 0)
		str = ft_strdup("0");
	else
	{
		if (nb != 0)
			len_po = ft_len_po(nb);
		else
			len_po = 0;
		len = len_po;
		str = ft_itoa_x(nb);
	}
	len = print_point(str, len, flags, nb);
	free(str);
	return (len);
}
