/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:40:54 by qraymaek          #+#    #+#             */
/*   Updated: 2023/11/29 14:43:34 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error(int n)
{
	if (n == 1)
		perror("error on input");
	else if (n == 2)
		perror("error on file open");
	else if (n == 3)
		perror("pipe error");
	else if (n == 4)
		perror("fork error");
	else
		perror("unknown error");
	exit(0);
}
