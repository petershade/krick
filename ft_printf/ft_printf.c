#include "sources/ft_printf.h"

int	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_parsing_flags(const char *format, int *i, t_flags *flags, va_list args)
{
	*i = ft_min(format, i, flags);
	*i = ft_width(format, i, flags, args);
	*i = ft_precision(format, i, flags, args);
	if (format[*i] == 'c' || format[*i] == 's' || format[*i] == 'p'
		|| format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'u'
		|| format[*i] == 'x' || format[*i] == 'X' || format[*i] == '%')
		flags->type = format[(*i)++];
	return (*i);
}

int	ft_print(t_flags *flags, va_list args)
{
	int	len;

	len = 0;
	if (flags->type == 'd' || flags->type == 'i')
		len = print_di(va_arg(args, int), flags);
	if (flags->type == 'u')
		len = print_u(va_arg(args, unsigned int), flags);
	if (flags->type == 'c')
		len = print_c(va_arg(args, int), flags);
	if (flags->type == 's')
		len = print_s(va_arg(args, char *), flags);
	if (flags->type == 'p')
		len = print_p(va_arg(args, unsigned long), flags);
	if (flags->type == 'x')
		len = print_x(va_arg(args, unsigned int), flags);
	if (flags->type == 'X')
		len = print_xx(va_arg(args, unsigned int), flags);
	if (flags->type == '%')
		len = print_s("%", flags);
	return (len);
}

int	ft_parsing_start(const char *format, va_list args)
{
	int		i;
	int		len;
	t_flags	flags;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			flags = ft_flags_start();
			i = ft_parsing_flags(format, &i, &flags, args);
			len += ft_print(&flags, args);
		}
		else if (format[i])
		{
			len += ft_putchar(format[i], 1);
			i++;
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	len += ft_parsing_start(format, args);
	va_end(args);
	return (len);
}
