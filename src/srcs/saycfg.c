#include "say.h"

int		main(int argc, char **argv)
{
	int			i;
	t_config	config;

	i = 0;
	ft_get_default_cfg(&config);
	if (ft_read_cfg(&config) == false)
		printf("Error occured while loading current configuration.\nDefault configuration will be used.\n");
	if (argc >= 2 && strcmp(argv[1], "-d") == 0)
	{
		ft_get_default_cfg(&config);
		if (ft_write_cfg(&config) == false)
			printf("Error occured while saving configuration.\n");
		else
			printf("Confguration saved successfully.\nLanguage: %s\nVolume: %f\nSpeed: %f\n", config.lng, config.vol, config.speed);
	}
	else if (argc >= 3)
	{
		argc--;
		argv++;
		while (argc && (strcmp(argv[i], "-l") == 0 ||
					strcmp(argv[i], "-s") == 0 ||
					strcmp(argv[i], "-v") == 0 ||
					strcmp(argv[i], "-f") == 0))
		{
			if (strcmp(argv[i], "-l") == 0)
				ft_check_flag_l(&config, argv[i + 1]);
			else if (strcmp(argv[i], "-s") == 0)
				ft_check_flag_s(&config, argv[i + 1]);
			else if (strcmp(argv[i], "-v") == 0)
				ft_check_flag_v(&config, argv[i + 1]);
			argc -= 2;
			argv += 2;
		}
		if (ft_write_cfg(&config) == false)
			printf("Error occured while saving configuration.\n");
		else
			printf("Confguration saved successfully.\nLanguage: %s\nVolume: %f\nSpeed: %f\n", config.lng, config.vol, config.speed);
	}
	else
		printf("Current configuration is:\nLanguage: %s\nVolume: %f\nSpeed: %f\n", config.lng, config.vol, config.speed);
	return (0);
}
