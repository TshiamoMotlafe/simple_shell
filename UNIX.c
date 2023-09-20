#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * main - Entry point of the simple_shell
 *
 * Description: This program implements a basic shell that accepts single-word
 * commands and executes them. It displays a prompt, waits for user input, and
 * executes the command.
 *
 * Return: 0 on success
 */
int main(void)
{
	char *buffer = NULL;

	size_t bufsize = 0;

	ssize_t read_chars;

	char *args[2];

	int status;

	while (1)
	{
	command = (char *)malloc(bufsize * sizeof(char));
	if (!command)
	{
	perror("malloc");
	exit(EXIT_FAILURE);
	}
	printf("#cisfun$ ");
	fflush(stdout);

	if (read_chars == -1)
	{
	if (feof(stdin))
	{
	printf("\n");
	free(command);
	exit(EXIT_SUCCESS);
	
	}
	perror("getline");
	exit(EXIT_FAILURE);
	}

	if (read_chars > 0 && buffer[read_chars - 1] == '\n')
	{
	command[read_chars - 1] = '\0';
	}

	pid_t child_ pid = fork();
	if (child_pid == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
        {
	exec_status = execve(command, NULL, environ);

	if (exec_status == -1)
	{
	perror("execve");
	free(command);
	exit(EXIT_FAILURE);
	}
	}
	else
	{
	waitpid(child_pid, &status, 0);
	if (status != 0)
		fprint(stderr, "./shell: No such file or directory\n");
	}
	free(command);
	}
	return (0);
}
