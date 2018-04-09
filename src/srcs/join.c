#include "say.h"

int	ft_join_tab_strlen(char **tab, int size)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			j++;
			k++;
		}
		i++;
	}
	return (k);
}

char	*ft_join(char **tab, int size)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*str;

	i = 0;
	k = 0;
	len = ft_join_tab_strlen(tab, size);
	str = NULL;
	if ((str = malloc(sizeof(char) * (len + size))) == NULL)
		return (NULL);
	while (i < size)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			str[k] = tab[i][j];
			j++;
			k++;
		}
		str[k] = ' ';
		k++;
		i++;
	}
	str[k - 1] = '\0';
	return (str);
}
