#include "say.h"

char	*itoa(int n)
{
	int		i;
	int		mul;
	char	*str;

	i = 0;
	mul = 1;
	str = NULL;
	while (n / mul >= 10)
		mul *= 10;
	if ((str = malloc(sizeof(char) * (mul / 10 + 2))) == NULL)
		return (NULL);
	while (mul >= 1)
	{
		str[i] = (n / mul) + '0';
		n %= 10;
		mul /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ftoa(float n)
{
	int		start;
	int		end;
	char	*sstart;
	char	*send;
	char	*res;

	start = (int) n;
	end = (n - start) * 1000000;
	sstart=itoa(start);
	send=itoa(end);
	res = ft_merge(".", 2, sstart, send);
	free(sstart);
	free(send);
	return (res);
}

void	ft_clean(char **str)
{
	int i;

	i = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '"' ||
				(*str)[i] == '\\' ||
				(*str)[i] == '(' || (*str)[i] == ')' ||
				(*str)[i] < ' ' || (*str)[i] >= 127)
			(*str)[i] =  ' ';
		i++;
	}
}
