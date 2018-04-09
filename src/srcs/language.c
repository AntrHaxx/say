#include "say.h"

char g_lngs[LNGS_LEN][6] = {
	"en-US\0",
	"en-GB\0",
	"fr-FR\0",
	"de-DE\0",
	"it-IT\0",
	"es-ES\0"
};

bool	ft_is_full_lng(char *lng)
{
	int i;

	i = 0;
	if (strlen(lng) != 5 ||
		!islower(lng[0]) ||
			!islower(lng[1]) ||
				lng[2] != '-' ||
					!isupper(lng[3]) ||
						!isupper(lng[4]))
		return (false);
	while (i < LNGS_LEN)
	{
		if (strcmp(g_lngs[i], lng) == 0)
			return (true);
		i++;
	}
	return (false);
}

bool	ft_is_short_lng(char *lng)
{
	int i;

	i = 0;
	if (strlen(lng) != 2 || !isalpha(lng[0]) || !isalpha(lng[1]))
		return (false);
	while (i < LNGS_LEN)
	{
		if (strstr(g_lngs[i], lng))
			return (true);
		i++;
	}
	return (false);
}

bool	ft_is_lng(char *lng)
{
	if (ft_is_full_lng(lng) || ft_is_short_lng(lng))
		return (true);
	return (false);
}

char	*ft_get_lng(char *lng)
{
	int i;

	i = 0;
	if (!ft_is_lng(lng))
		return (NULL);
	while (i < LNGS_LEN)
	{
		if (strstr(g_lngs[i], lng))
			return (g_lngs[i]);
		i++;
	}
	return (NULL);
}

int		ft_get_lng_index(char *lng)
{
	int i;

	i = 0;
	if (!ft_is_lng(lng))
		return (-1);
	while (i < LNGS_LEN)
	{
		if (strstr(g_lngs[i], lng))
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_get_system_lng(void)
{
	char *lng;

	lng = setlocale(LC_CTYPE, "");
	lng[2] = '-';
	lng[5] = '\0';
	return (lng);
}

char	*ft_get_default_lng(void)
{
	char *sysln;

	sysln = NULL;
	sysln = ft_get_system_lng();
	return (ft_is_lng(sysln) ? sysln : g_lngs[0]);
}
