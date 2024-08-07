/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:52:35 by mfassbin          #+#    #+#             */
/*   Updated: 2024/08/07 18:36:59 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>

int error(char *str)
{
	while(*str)
		write(STDERR_FILENO, str++, 1);
	return (1);
}

int exec_cd(char **argv, int i)
{
	if (i != 2)
		return(error("error: cd: bad arguments\n"));
	if (chdir(argv[1]) == -1)
		return(error("cd: cannot change directory to "), error(argv[1]), error("\n"));
	return(0);
}

int exec(char **argv, int i, char **envp)
{
	int fd[2];
	int pid;
	int status;
	bool has_pipe;

	has_pipe = argv[i] && !strcmp(argv[i], "|");
	if (!has_pipe && !strcmp(*argv, "cd"))
		return (exec_cd(argv, i));
	if (has_pipe && pipe(fd) == -1)
		return (error("error fatal\n"));
	pid = fork();
	if (pid == 0)
	{
		argv[i] = 0;
		if (!strcmp(*argv, "cd"))
			return(exec_cd(argv, i));
		if (has_pipe)
		{
			if (dup2(fd[1], STDOUT_FILENO) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
				return(error("error fatal\n"));
		}
		execve(*argv, argv, envp);
		return(error("error: cannot execute "), error(*argv), error("\n"));
	}
	waitpid(pid, &status, 0);
	if (has_pipe)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
			return(error("error fatal\n"));
	}
	if (WIFEXITED(status))
		return(WEXITSTATUS(status));
	return (1);
}


int main(int argc, char **argv, char **envp)
{
	int		i;
	int		status;

	i = 0;
	if (argc > 1)
	{	
		while(argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while(argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			if (i)
				status = exec(argv, i, envp);
			
		}
	}
	return (status);
}