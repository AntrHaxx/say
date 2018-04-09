#include "say.h"

bool	ft_read_cfg(t_config *config)
{
	FILE	*file;
	char	*path;

	file = NULL;
	path=ft_merge("\0", 2, getenv("HOME"), "/.say.cfg");
	file = fopen(path, "rb");
	free(path);
	if (file == NULL)
		return (false);
	fread(config->lng, sizeof(char), 6, file);
	fread(&(config->vol), sizeof(float), 1, file);
	fread(&(config->speed), sizeof(float), 1, file);
	fread(&(config->saying), sizeof(bool), 1, file);
	fclose(file);
	return (true);
}

bool	ft_write_cfg(t_config *config)
{
	FILE	*file;
	char	*path;

	file = NULL;
	path=ft_merge("\0", 2, getenv("HOME"), "/.say.cfg");
	file = fopen(path, "wb");
	free(path);
	if (file == NULL)
		return (false);
	fwrite(config->lng, sizeof(char), 6, file);
	fwrite(&(config->vol), sizeof(float), 1, file);
	fwrite(&(config->speed), sizeof(float), 1, file);
	fwrite(&(config->saying), sizeof(bool), 1, file);
	fclose(file);
	return (true);
}

void	ft_get_default_cfg(t_config *config)
{
	config->lng = ft_get_default_lng();
	config->speed = 1;
	config->vol = 1;
	config->saying = false;
}
