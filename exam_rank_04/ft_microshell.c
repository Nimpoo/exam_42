/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train_microshell_#16.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:22:29 by mayoub            #+#    #+#             */
/*   Updated: 2023/01/03 12:43:18 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	ft_strcpy(char *dst, char *src)
{
	while ((*dst++ = *src++))
		;
}

int	is_ope(char *str)
{
	if (!strcmp("|", str) || !strcmp(";",str))
		return (1);
	return (0);
}

int	ft_cmdlen(char **str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

void	error_exec(char *str)
{
	write(2, "error: cannot execute ", 22);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(0);
}

void	ft_microshell(char ** av, char **env, int in)
{
	char	**cmd = malloc(sizeof(char *) * 100);
	int		fd[2], i = 0, std_tmp = STDIN_FILENO;

	if (!cmd)
		(write(2, "error: fatal\n", 13), exit(0));
	if (av[i] && is_ope(av[i]))
		av++;
	while (av[i] && !is_ope(av[i]))
	{
		cmd[i] = malloc(sizeof(char) * 100);
		if (!cmd[i])
			(write(2, "error: fatal\n", 13), exit(0));
		ft_strcpy(cmd[i], av[i]);
		i++;
	}
	if (av[i] && !strcmp("|", av[i]))
	{
		pipe(fd);
		if (fork() == 0)
		{
			dup2(in, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
			if (execve(cmd[0], cmd, env) == -1)
				error_exec(cmd[0]);
			exit(0);
		}
		close(fd[1]);
		std_tmp = fd[0];
	}
	else
	{
		if (fork() == 0)
		{
			dup2(in, STDIN_FILENO);
			if (!strcmp("cd", cmd[0]))
			{
				if (ft_cmdlen(cmd) != 2)
					(write(2, "error: cd: bad arguments\n", 25), exit(0));
				else if (chdir(cmd[1]) == -1)
				{
					write(2, "erorr: cd: cannot change directory to ", 38);
					write(2, cmd[1], ft_strlen(cmd[1]));
					write(2, "\n", 1);
					exit(0);
				}
			}
			else if (execve(cmd[0], cmd, env) == -1)
				error_exec(cmd[0]);
			exit(0);
		}
	}
	if (in != STDIN_FILENO)
		close(in);
	av += i;
	waitpid(0, NULL, 0);
	if (*av)
		ft_microshell(av, env, std_tmp);
}

int	main(int ac, char **av, char **env)
{
	if (ac > 1)
		ft_microshell(++av, env, STDIN_FILENO);
	return (0);
}

