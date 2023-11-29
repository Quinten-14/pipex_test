/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:05:34 by qraymaek          #+#    #+#             */
/*   Updated: 2023/11/29 14:43:39 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// error handling
void	error(int n);

// utils
int		ft_strcmp(char *s1, char *s2);
void	ft_free_tab(char **tab);
char	*my_getenv(char *name, char **env);
char	*get_path(char *cmd, char **env);
void	doc_put(char **av, int *p_fd);

#endif
