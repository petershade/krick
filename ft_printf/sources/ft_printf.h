#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
	int			minus;
	int			zero;
	int			width;
	int			precision;
	int			type;
}				t_flags;

t_flags	ft_flags_start(void);
int		ft_printf(const char *format, ...);
int		ft_parsing_start(const char *format, va_list args);
int		ft_print(t_flags *flags, va_list args);
int		ft_parsing_flags(const char *format, \
int *i, t_flags *flags, va_list args);
int		ft_putchar(char c, int fd);
char	*ft_itoa(unsigned int num);
int		ft_isdigit(int c);
char	*ft_strdup(const char *string);
int		ft_min(const char *format, int *i, t_flags *flags);
int		ft_width(const char *format, int *i, t_flags *flags, va_list args);
int		ft_precision2(const char *format, int *i, t_flags *flags);
int		ft_precision(const char *format, int *i, t_flags *flags, va_list args);
int		print_c(char c, t_flags *flags);
int		ft_print_width(int width, int zero);
size_t	ft_strlen(const char *str);
void	ft_putstr(char *str);
void	ft_putnstr(char *str, int num);
int		print_s(char *str, t_flags *flags);
int		print_di(int num, t_flags *flags);
int		print_pos_di(int num, t_flags *flags);
int		print_neg_di(int n, t_flags *flags);
int		print_u(unsigned int num, t_flags *flags);
char	*ft_itoa_x(unsigned long num);
int		print_x(unsigned int num, t_flags *flags);
char	*ft_itoa_xx(unsigned long num);
int		print_xx(unsigned int num, t_flags *flag);
int		pre_point(char *str, int len, t_flags *flags, unsigned long nb);
int		wid_point(char *str, int len, t_flags *flags);
int		print_p(unsigned long nb, t_flags *flags);
int		print_point(char *str, int len, t_flags *flag, unsigned long nb);

#endif