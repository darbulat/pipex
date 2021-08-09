#ifndef PIPEX_H

# define PIPEX_H

# include "libft/libft.h"
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_file_path(char *file, char **env);
char	*get_command_path(char **env, char *cmd);
char	*get_path_by_key(char **env, char *key);
void	error_exit(const char *error);

#endif //PIPEX_H
