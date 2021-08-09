#include "pipex.h"

void	main_process(int *fd, char **argv, char **env)
{
	int		fd_out;
	char	**cmd;
	char	*file2;
	char	*path;

	wait(NULL);
	file2 = get_file_path(argv[4], env);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	cmd = ft_split(argv[3], ' ');
	fd_out = open(file2, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd_out == -1)
		error_exit(file2);
	dup2(fd_out, 1);
	path = get_command_path(env, cmd[0]);
	if (execve(path, cmd, NULL) == -1)
		error_exit(cmd[0]);
}

void	child_process(int *fd, char **argv, char **env)
{
	int		fd_in;
	char	**cmd;
	char	*file1;
	char	*path;

	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	file1 = get_file_path(argv[1], env);
	fd_in = open(file1, O_RDONLY);
	if (fd_in == -1)
		error_exit("./pipex");
	dup2(fd_in, 0);
	cmd = ft_split(argv[2], ' ');
	path = get_command_path(env, cmd[0]);
	if (execve(path, cmd, NULL) == -1)
		error_exit("Command not found");
}

int	main(int argc, char **argv, char **env)
{
	int	pid;
	int	fd[2];

	if (argc < 1)
		error_exit("Not enough arguments");
	if (pipe(fd) == -1)
		error_exit("./pipex");
	pid = fork();
	if (pid == -1)
		error_exit("Error while forking");
	if (pid == 0)
		child_process(fd, argv, env);
	else
		main_process(fd, argv, env);
}
