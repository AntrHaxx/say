#ifndef __SAY_H__
#define __SAY_H__

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <locale.h>
#include <math.h>

#define LNGS_LEN 6

typedef struct	s_config
{
	float		speed;
	float		vol;
	char		*lng;
	bool		saying;
	char		*output;
}				t_config;

// Merge Functions: Converts arguments to string
void	ft_merge_append(char **str, char **tmp, char **sep);
char	*ft_merge(char *sep, int argc, ...);

// Join Functions: Converts array to string
int		ft_join_tab_strlen(char **tab, int size);
char	*ft_join(char **tab, int size);

// Language funcitons: Test, get and set language
bool	ft_is_lng( char*lng);
bool	ft_is_full_lng( char*lng);
bool	ft_is_short_lng(char *lng);
char	*ft_get_lng(char *lng);
int		ft_get_lng_index(char *lng);
char	*ft_get_system_lng(void);
char	**ft_get_lngs(void);
char	*ft_get_default_lng(void);

// Read Functions: Read data from file descriptors
bool	ft_read_fd(int fd, char **str);
bool	ft_read_file(char *file, char **str);
bool	ft_read_stdin(char **str);

// Say Funcitons: Manage synthesis and player
void	ft_shutup(void);
void	ft_say(char **str, t_config *config);

// Config Functions: Manage config
bool	ft_read_cfg(t_config *cfg);
bool	ft_write_cfg(t_config *config);
void	ft_get_default_cfg(t_config *config);
void	ft_args_to_cfg(char **str, t_config *config, int argc, char **argv);
void	ft_check_cfg(t_config *config, char **str, int *argc, char ***argv);
int		ft_is_flag(char *s1, char *s2, char *s3);

// Config Check Functions: Check config elements
bool	ft_check_flag_l(t_config *config, char *arg);
bool	ft_check_flag_s(t_config *config, char *arg);
bool	ft_check_flag_v(t_config *config, char *arg);
bool	ft_check_flag_f(char **str, char *arg);

// String Functions: String helpers
void	ft_clean(char **str);
char	*itoa(int n);
char	*ftoa(float n);

//	System Functions: Functions overlays for system calls
void ft_system(char *input);

#endif
