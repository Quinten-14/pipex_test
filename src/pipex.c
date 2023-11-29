/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:54:34 by qraymaek          #+#    #+#             */
/*   Updated: 2023/11/29 14:43:44 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/pipex.h"

void	exec(char *cmd, char **envp)
{
	char	**cmd_parsed;
	char	*path;

	cmd_parsed = ft_split(cmd, ' ');
	path = get_path(cmd_parsed[0], envp);
	if (execve(path, cmd_parsed, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd_parsed[0], 2);
		ft_free_tab(cmd_parsed);
		exit(0);
	}
}

int	check_ac_and_doc(int ac, char **av)
{
	size_t	i;
	char	*str;
	char	*str2;

	if (ac == 1)
		write(2, "usage: ./pipex file1 cmd1 cmd2 file2\n", 37);
	str = av[1];
	str2 = "here_doc";
	i = 0;
	if (ac < 5)
	{
		error(1);
	}
	while (str[i] || str2[i])
	{
		if (str[i] != str2[i])
			return (0);
		i++;
	}
	if (ac < 6)
		error(1);
	return (1);
}

void	doc(char **av)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		error(3);
	pid = fork();
	if (pid == -1)
		error(4);
	if (!pid)
		doc_put(av, p_fd);
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		wait(NULL);
	}
}

void	ft_pipe(char *cmd, char **envp)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		error(3);
	pid = fork();
	if (pid == -1)
		error(4);
	if (!pid)
	{
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		exec(cmd, envp);
	}
	else
	{
		close(p_fd[1]);
		wait(NULL);
		dup2(p_fd[0], 0);
	}
}

int	main(int ac, char **av, char **envp)
{
	int		fd;
	int		p_fd;
	size_t	i;

	if (check_ac_and_doc(ac, av) == 1)
	{
		i = 3;
		p_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (p_fd == -1)
			error(2);
		doc(av);
	}
	else
	{
		i = 2;
		fd = open(av[1], O_RDONLY, 0777);
		p_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
			error(2);
		dup2(fd, 0);
	}
	while (i < ac - 2)
		ft_pipe(av[i++], envp);
	dup2(p_fd, 1);
	exec(av[ac - 2], envp);
}
