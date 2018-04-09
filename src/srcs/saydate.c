#include "say.h"

int		main(void)
{
	t_config config;


	ft_get_default_cfg(&config);
	ft_read_cfg(&config);
	system(ft_merge("\0", 3, "/usr/bin/say_deps/date/", config.lng, ".sh"));
}
