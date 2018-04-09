#include "say.h"

int		main(int argc, char **argv)
{
	int			i;
	char		*str;
	char		*path;
	t_config	config;

	i = 0;
	argc--;
	argv++;
	str = NULL;
	ft_get_default_cfg(&config);
	ft_read_cfg(&config);
	if (argc && strcmp(argv[0], "xsel") == 0)
	{
		path=ft_merge("\0", 2, getenv("HOME"), "/.say.txt");
		system("xsel > ~/.say.txt");
		ft_read_file(path, &str);
		free(path);
	}
	else if (argc)
	{
		if (argc >= 2)
		{
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
				else if (strcmp(argv[i], "-f") == 0)
					ft_check_flag_f(&str, argv[i + 1]);
				argc -= 2;
				argv += 2;
			}
		}
		if (argc)
		{
			if (str == NULL)
				str = ft_join(argv, argc);
		}
		else if (str == NULL)
			ft_read_stdin(&str);
	}
	else if (str == NULL)
		ft_read_stdin(&str);
	if (str != NULL)
	{
		if (argc && strcmp(argv[0], "xsel") == 0 && config.saying == true)
		{
			config.saying = false;
			ft_write_cfg(&config);
			ft_shutup();
		}
		else
		{
			if (argc && strcmp(argv[0], "xsel") == 0)
			{
				config.saying = true;
				ft_write_cfg(&config);
			}
			ft_say(&str, &config);
			if (argc && strcmp(argv[0], "xsel") == 0)
			{
				config.saying = false;
				ft_write_cfg(&config);
			}
		}
		free(str);
	}
	return (0);
}
