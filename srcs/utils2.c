/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:16:31 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/07 13:16:33 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_close_close(int fd1, int fd2, int fd3, int fd4)
{
	close_fd(fd1, fd2);
	close_fd(fd3, fd4);
}

void	open_otfile_if_failed(int fd, char *str)
{
	fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		if (fd != -1)
			close(fd);
		perror(str);
	}
}

void	open_null_as_fallback(char *path)
{
	int	null_fd;

	null_fd = open(path, O_WRONLY);
	if (null_fd != -1)
	{
		dup2(null_fd, STDOUT_FILENO);
		close(null_fd);
	}
}

void	check_cmd(int *state, int i)
{
	close(*state);
	*state = 0;
	if (i == 1)
		*state = 127;
}
