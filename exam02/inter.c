#include <unistd.h>

int ft_check(char c, char *str, int k)
{
	int i;

	i = -1;
	while (++i < k)
		if (str[i] == c)
			return(0);
	return(1);
}

void ft_union(char *str1, char *str2)
{
	int i;
	int j;
	int opa;

	i = -1;
	j = -1;
	opa = 0;
	while (str2[opa])
		opa++;
	while (str1[++i])
		if (ft_check(str1[i], str1, i) && !ft_check(str1[i], str2, opa))
			write(1, &str1[i], 1);
}

int main(int argc, char **argv) {
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
