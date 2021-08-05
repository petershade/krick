#include "sources/ft_printf.h"

static int	ft_len_xx(unsigned long num)
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

char	*ft_itoa_xx(unsigned long num)
{
	int		len;
	char	*str;

	len = ft_len_xx(num);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	str[0] = '0';
	while (len >= 0)
	{
		if (num % 16 >= 10)
			str[len--] = (num % 16) + 55;
		else
			str[len--] = (num % 16) + 48;
		num /= 16;
	}
	return (str);
}

static int	ft_pos_prec_xx(t_flags *flags, int len_x, int len, char *str)
{
	if (flags->width > flags->precision && flags->minus == 0)
	{
		if (flags->precision > len_x)
			len += ft_print_width(flags->width - flags->precision, 0);
		else if (flags->width > len_x)
			len += ft_print_width(flags->width - len_x, 0);
	}
	if (flags->precision > len_x)
		len += ft_print_width(flags->precision - len_x, 1);
	ft_putstr(str);
	if (flags->width > flags->precision && flags->minus)
	{
		if (flags->precision > len_x)
			len += ft_print_width(flags->width - flags->precision, 0);
		else if (flags->width > len_x)
			len += ft_print_width(flags->width - ft_strlen(str), 0);
	}
	return (len);
}

static int	ft_neg_prec_xx(t_flags *flags, int len_x, int len, char *str)
{
	if (flags->width > len_x && flags->minus == 0)
	{
		if (flags->zero == 1)
			len += ft_print_width(flags->width - len_x, 1);
		else
			len += ft_print_width(flags->width - len_x, 0);
	}
	ft_putstr(str);
	if (flags->width > len_x && flags->minus == 1)
		len += ft_print_width(flags->width - len_x, 0);
	return (len);
}

int	print_xx(unsigned int num, t_flags *flags)
{
	unsigned long	nbr;
	int				len;
	int				len_x;
	char			*str;

	len = 0;
	if (flags->precision == 0 && num == 0)
	{
		len += ft_print_width(flags->width, 0);
		return (len);
	}
	nbr = (unsigned long)num;
	len_x = ft_len_xx(nbr);
	str = ft_itoa_xx(nbr);
	if (flags->precision == -1)
		len += ft_neg_prec_xx(flags, len_x, len, str);
	if (flags->precision >= 0)
		len += ft_pos_prec_xx(flags, len_x, len, str);
	free(str);
	return (len + len_x);
}
