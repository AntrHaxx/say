#include "say.h"

void	ft_merge_append(char **str, char **tmp, char **sep)
{
	int i;
	int j;
	int	strl;
	int	tmpl;
	int sepl;
	int first;

	i = 0;
	j = 0;
	first = *str == NULL ? 1 : 0;
	strl=*str != NULL ? strlen(*str) : 0;
	tmpl=*tmp != NULL ? strlen(*tmp) : 0;
	sepl=*sep != NULL ? strlen(*sep) : 0;
	*str = realloc(*str, strl + tmpl + sepl + first);
	while ((*str)[i] != '\0' && i < strl)
		i++;
	if (i != 0)
	{
		while ((*sep)[j] != '\0')
		{
			(*str)[i] = (*sep)[j];
			i++;
			j++;
		}
	}
	j = 0;
	while ((*tmp)[j] != '\0')
	{
		(*str)[i] = (*tmp)[j];
		i++;
		j++;
	}
	(*str)[i] = '\0';
}

char	*ft_merge(char *sep, int argc, ...)
{
	int			i;
	char		*str;
	char		*tmp;
	va_list		valist;

	i = 0;
	str = NULL;
	tmp = NULL;
	va_start(valist, argc);
	while (i < argc)
	{
		tmp = va_arg(valist, char*);
		ft_merge_append(&str, &tmp, &sep);
		i++;
	}
	va_end(valist);
	return (str);
}
