#include "say.h"

void	ft_check_cfg(t_config *config, char **str, int *argc, char ***argv)
{
	while (*argc)
	{
		if (ft_is_flag((*argv)[0], "-l", "--language"))
			ft_check_flag_l(config, (*argv)[1]);
		else if (ft_is_flag((*argv)[0], "-s", "--speed"))
			ft_check_flag_s(config, (*argv)[1]);
		else if (ft_is_flag((*argv)[0], "-v", "--volume"))
			ft_check_flag_v(config, (*argv)[1]);
		else if (ft_is_flag((*argv)[0], "-f", "--file"))
			ft_check_flag_f(str, (*argv)[1]);
		else if (ft_is_flag((*argv)[0], "-o", "--output"))
			config->output = (*argv)[1];
		else
			break;
		*argc -= 2;
		*argv += 2;
	}
}

int		main(int argc, char **argv)
{
	char		*str;
	char		*path;
	t_config	config;

	argc--;
	argv++;
	str = NULL;
	ft_get_default_cfg(&config);
	ft_read_cfg(&config);
	if (argc && ft_is_flag(argv[0], "-h", "--help"))
	{
		system("cat /usr/bin/say_deps/help");
	}
	else if (argc && ft_is_flag(argv[0], "-c", "--config"))
	{
		if (argc >= 2 && ft_is_flag(argv[1], "-d", "--default"))
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
			ft_check_cfg(&config, &str, &argc, &argv);
			if (ft_write_cfg(&config) == false)
				printf("Error occured while saving configuration.\n");
			else
				printf("Confguration saved successfully.\nLanguage: %s\nVolume: %f\nSpeed: %f\n", config.lng, config.vol, config.speed);
		}
		else
			printf("Current configuration is:\nLanguage: %s\nVolume: %f\nSpeed: %f\n", config.lng, config.vol, config.speed);
	}
	else if (argc && (ft_is_flag(argv[0], "-x", "--xsel") || strcmp(argv[0], "xsel") == 0))
	{
		path=ft_merge("\0", 2, getenv("HOME"), "/.say.txt");
		system("xsel > ~/.say.txt");
		ft_read_file(path, &str);
		free(path);
		if (argc >= 3)
		{
			argc--;
			argv++;
			ft_check_cfg(&config, &str, &argc, &argv);
		}
	}
	else if (argc)
	{
		if (argc >= 2)
			ft_check_cfg(&config, &str, &argc, &argv);
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
		if (argc && ft_is_flag(argv[0], "-x", "--xsel") && config.saying == true)
		{
			config.saying = false;
			ft_write_cfg(&config);
			ft_shutup();
		}
		else
		{
			if (argc && ft_is_flag(argv[0], "-x", "--xsel"))
			{
				config.saying = true;
				ft_write_cfg(&config);
			}
			ft_say(&str, &config);
			if (config.output != NULL)
			{
				path = ft_merge(" ", 2, "mv ~/.say.wav", config.output);
				system(path);
				free(path);
			}
			else
				system("/bin/rm ~/.say.wav");
			if (argc && ft_is_flag(argv[0], "-x", "--xsel"))
			{
				config.saying = false;
				ft_write_cfg(&config);
			}
		}
		free(str);
	}
	return (0);
}
