#include "ft_printf.h"

static int	ft_pos_prec_unsign(t_flags *flags, \
int len_unsign, int len, char *unsign)
{
	if (flags->width > flags->precision && flags->minus == 0)
	{
		if (flags->precision > len_unsign)
			len += ft_print_width(flags->width - flags->precision, 0);
		else if (flags->width > len_unsign)
			len += ft_print_width(flags->width - len_unsign, 0);
	}
	if (flags->precision > len_unsign)
		len += ft_print_width(flags->precision - len_unsign, 1);
	ft_putstr(unsign);
	if (flags->width > flags->precision && flags->minus)
	{
		if (flags->precision > len_unsign)
			len += ft_print_width(flags->width - flags->precision, 0);
		else if (flags->width > len)
			len += ft_print_width(flags->width - ft_strlen(unsign), 0);
	}
	return (len);
}

static int	ft_neg_prec_unsign(t_flags *flags, \
int len_unsign, int len, char *unsign)
{
	if (flags->width > len_unsign && flags->minus == 0)
	{
		if (flags->zero == 1)
			len += ft_print_width(flags->width - len_unsign, 1);
		else
			len += ft_print_width(flags->width - len_unsign, 0);
	}
	ft_putstr(unsign);
	if (flags->width > len_unsign && flags->minus == 1)
		len += ft_print_width(flags->width - len_unsign, 0);
	return (len);
}

int	print_u(unsigned int num, t_flags *flags)
{
	int		len;
	int		len_unsign;
	char	*unsign;

	len = 0;
	if (flags->precision == 0 && num == 0)
	{
		len += ft_print_width(flags->width, 0);
		return (len);
	}
	unsign = ft_itoa(num);
	len_unsign = ft_strlen(unsign);
	if (flags->precision == -1)
		len += ft_neg_prec_unsign(flags, len_unsign, len, unsign);
	if (flags->precision >= 0)
		len += ft_pos_prec_unsign(flags, len_unsign, len, unsign);
	free(unsign);
	return (len + len_unsign);
}
