#include "say.h"

void	ft_shutup(void)
{
	system("killall play");
}

void	ft_say(char **str, t_config *config)
{
	char *speed;
	char *vol;
	char *lng;
	char *pico;
	char *say;

	ft_clean(str);
	vol = ftoa(config->vol);
	speed = ftoa(config->speed);
	lng = config->lng;
	pico = ft_merge("\0", 5, "pico2wave -l ", lng, " -w ~/.say.wav \"", *str, "\"");
	say = ft_merge(" ", 4, "play -q ~/.say.wav vol", vol, "speed", speed);
	system(pico);
	system(say);
	free(vol);
	free(speed);
	free(pico);
	free(say);
}
