#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int	print_error(char *error_message)
{
	while (*error_message)
		write(2, error_message++, 1);
	return (1);
}

int	execute_command(char **command_line, char **environment, int command_index)
{
	int	process_status;
	int	pipe_file_descriptors[2];
	int	is_pipe_present = command_line[command_index]&& !strcmp(command_line[command_index], "|");

	if (is_pipe_present && pipe(pipe_file_descriptors) == -1)
		return (print_error("error: fatal\n"));
	int	child_pid = fork();
	if (!child_pid)
	{
		command_line[command_index] = 0;
		if (is_pipe_present && (dup2(pipe_file_descriptors[1], 1) == -1 || close(pipe_file_descriptors[0]) == -1 || close(pipe_file_descriptors[1]) == -1))
			return (print_error("error: fatal\n"));
		execve(*command_line, command_line, environment);
		return (print_error("error: cannot execute "), print_error(*command_line), print_error("\n"));
	}
	waitpid(child_pid, &process_status, 0);
	if (is_pipe_present && (dup2(pipe_file_descriptors[0], 0) == -1 || close(pipe_file_descriptors[0]) == -1 || close(pipe_file_descriptors[1]) == -1))
		return (print_error("error: fatal\n"));
	return (WIFEXITED(process_status) && WEXITSTATUS(process_status));
}

int	change_directory(char **command_line, int command_index)
{
	if (command_index != 2)
		return (print_error("error: cd: bad arguments\n"));
	else if (chdir(command_line[1]) == -1)
		return (print_error("error: cd: cannot execute "), print_error(command_line[1]), print_error("\n"));
	return (0);
}

int	main(int argc, char **argv, char **environment)
{
	int	command_index = 0;
	int	exit_status = 0;

	if (argc > 1)
	{
		while (argv[command_index] && argv[++command_index])
		{
			argv += command_index;
			command_index = 0;
			while (argv[command_index] && strcmp(argv[command_index], "|")
				&& strcmp(argv[command_index], ";"))
				command_index++;
			if (!strcmp(*argv, "cd"))
				exit_status = change_directory(argv, command_index);
			else if (command_index)
				exit_status = execute_command(argv, environment, command_index);
		}
	}
	return (exit_status);
}
