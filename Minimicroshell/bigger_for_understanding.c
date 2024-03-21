#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void	print_error(char *first_error_message, char *second_error_message)
{
	while (*first_error_message)
		write(2, first_error_message++, 1);
	if (second_error_message)
		while (*second_error_message) write(2, second_error_message++, 1);
	write(2, "\n", 1);
}

void	execute_command(char *args[], int command_end, int read_end, char *environment[])
{
	args[command_end] = NULL;												// Terminate the args array for execve
	dup2(read_end, STDIN_FILENO);											// Duplicate read end to stdin
	close(read_end);														// Close the original read end
	execve(args[0], args, environment);										// Execute the command
	print_error("error: cannot execute ", args[0]);							// Print error if execve fails
}

int	main(int argc, char *argv[], char *environment[])
{
	int	arg_index = 0, pipe_fds[2], stdin_copy = dup(STDIN_FILENO);

	(void)argc;																// Unused parameter
	while (argv[arg_index] && argv[arg_index + 1])
	{
		argv = &argv[arg_index + 1];										// Shift to the next command
		arg_index = 0;
		while (argv[arg_index] && strcmp(argv[arg_index], ";")
			&& strcmp(argv[arg_index], "|"))
			arg_index++;
		if (!strcmp(argv[0], "cd"))											// If the command is 'cd'
		{
			if (arg_index != 2)
				print_error("error: cd: bad arguments", NULL);
			else if (chdir(argv[1]))
				print_error("error: cd: cannot change directory to ", argv[1]);
		}
		else if (arg_index && (!argv[arg_index] || !strcmp(argv[arg_index], ";")))
		{
			if (!fork())													// If child process
				execute_command(argv, arg_index, stdin_copy, environment);	// Execute the command
			else
			{
				close(stdin_copy);											// Parent closes the copy of stdin
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;														// Wait for child process
				stdin_copy = dup(STDIN_FILENO);								// Duplicate stdin again for the next command
			}
		}
		else if (arg_index && !strcmp(argv[arg_index], "|"))
		{
			pipe(pipe_fds);													// Create a pipe
			if (!fork())													// If child process
			{
				dup2(pipe_fds[1], STDOUT_FILENO);							// Duplicate write end to stdout
				close(pipe_fds[0]);											// Close read end
				close(pipe_fds[1]);											// Close write end
				execute_command(argv, arg_index, stdin_copy, environment);	// Execute the command
			}
			else															// Parent process
			{
				close(pipe_fds[1]);											// Close write end
				close(stdin_copy);											// Close the copy of stdin
				stdin_copy = pipe_fds[0];									// Use read end for the next command
			}
		}
	}
	close(stdin_copy);														// Close the stdin copy at the end
	return (0);
}
