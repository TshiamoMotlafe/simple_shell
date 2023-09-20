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
	printf("$ ");
	read_chars = getline(&buffer, &bufsize, stdin);

	if (read_chars == -1)
	{
	if (feof(stdin))
	{
	printf("\n");
	break;
	}
	perror("getline");
	exit(EXIT_FAILURE);
	}

	if (read_chars > 0 && buffer[read_chars - 1] == '\n')
	{
	buffer[read_chars - 1] = '\0';
	}
	 args[0] = buffer;
	args[1] = NULL;

	pid_t child_pid = fork();
	if (child_pid == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
        {
	if (execve(args[0], args, NULL) == -1)
	{
	perror("execve");
	exit(EXIT_FAILURE);
	}
	}
	else
	{
	waitpid(child_pid, &status, 0);
	}
	}

	free(buffer);
	return (0);
}
