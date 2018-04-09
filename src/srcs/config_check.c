#include "say.h"

bool	ft_check_flag_l(t_config *config, char *arg)
{
	if (!ft_is_lng(arg))
		return (false);
	config->lng = ft_get_lng(arg);
	return (true);
}

bool	ft_check_flag_s(t_config *config, char *arg)
{
	float	n;

	n = atof(arg);
	if (n < 0.5 || n > 1.5)
		return (false);
	config->speed = n;
	return (true);
}

bool	ft_check_flag_v(t_config *config, char *arg)
{
	float n;

	n = atof(arg);
	if (n < 0.5 || n > 1.5)
		return (false);
	config->vol = n;
	return (true);
}

bool	ft_check_flag_f(char **str, char *arg)
{
	return (ft_read_file(arg, str));
}
