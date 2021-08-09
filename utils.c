#include "pipex.h"

void	error_exit(const char *error)
{
	perror(error);
	exit(errno);
}

char	*get_path_by_key(char **env, char *key)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], key, ft_strlen(key)))
			return (env[i] + ft_strlen(key));
		i++;
	}
	return (NULL);
}

char	*get_command_path(char **env, char *cmd)
{
	char	*path;
	char	**paths;
	int		i;
	char	*tmp_command;

	path = get_path_by_key(env, "PATH=");
	paths = ft_split(path, ':');
	tmp_command = ft_strjoin("/", cmd);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], tmp_command);
		if (access(path, 0) == 0)
		{
			free(tmp_command);
			return (path);
		}
		i++;
		free(path);
	}
	return (NULL);
}

char	*get_file_path(char *file, char **env)
{
	char	*command_path;
	char	*tmp_path;
	char	*file_path;

	if (file[0] == '/')
		return (file);
	command_path = get_path_by_key(env, "PWD=");
	tmp_path = ft_strjoin("/", file);
	file_path = ft_strjoin(command_path, tmp_path);
	free(tmp_path);
	return (file_path);
}
