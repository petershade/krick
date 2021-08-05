#include "sources/ft_printf.h"

t_flags	ft_flags_start(void)
{
	t_flags		flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.type = 0;
	return (flags);
}

int	ft_min(const char *format, int *i, t_flags *flags)
{
	while (format[*i] == '-' || format[*i] == '0')
	{
		if (format[*i] == '-')
			flags->minus = 1;
		else if (format[*i] == '0')
			flags->zero = 1;
		(*i)++;
	}
	if (flags->minus == 1)
		flags->zero = 0;
	return (*i);
}

int	ft_width(const char *format, int *i, t_flags *flags, va_list args)
{
	if (format[*i] == '*')
	{
		flags->width = va_arg(args, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= -1;
		}
		(*i)++;
	}
	while (ft_isdigit(format[*i]))
	{
		flags->width = (flags->width * 10) + (format[*i] - '0');
		(*i)++;
	}
	return (*i);
}

int	ft_precision2(const char *format, int *i, t_flags *flags)
{
	int	num;
	int	f;

	num = 0;
	f = 0;
	if (format[*i] == '-')
	{
		flags->minus = 1;
		flags->precision = 0;
		f = 1;
		(*i)++;
	}
	while (ft_isdigit(format[*i]))
	{
		num = (num * 10) + (format[*i] - '0');
		(*i)++;
	}
	if (f == 0)
		flags->precision = num;
	else if (f == 1)
		flags->width = num;
	return (*i);
}

int	ft_precision(const char *format, int *i, t_flags *flags, va_list args)
{
	int	num;

	num = 0;
	if (format[*i] == '.')
	{
		(*i)++;
		if (format[*i] == '*')
		{
			num = va_arg(args, int);
			if (num >= 0)
				flags->precision = num;
			(*i)++;
		}
		else
			*i = ft_precision2(format, i, flags);
	}
	return (*i);
}
