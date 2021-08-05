#include "sources/ft_printf.h"

int	ft_print_width(int width, int zero)
{
	int	len_char;

	len_char = 0;
	while (width > 0)
	{
		if (zero)
			ft_putchar('0', 1);
		else
			ft_putchar(' ', 1);
		width--;
		len_char++;
	}
	return (len_char);
}

int	print_c(char c, t_flags *flags)
{
	int	len_char;

	len_char = 0;
	if (flags->minus == 1)
		ft_putchar(c, 1);
	if (flags->zero == 1)
		len_char = ft_print_width(flags->width - 1, 1);
	else
		len_char = ft_print_width(flags->width - 1, 0);
	if (flags->minus == 0)
		ft_putchar(c, 1);
	return (len_char + 1);
}
