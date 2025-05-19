/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:46:44 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/01 15:46:46 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_args(char ***str)
{
	int	i;
	int	j;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			free(str[i][j]);
			j++;
		}
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_arr_arr(char ***str, int i)
{
	int	j;

	while (i >= 0)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j])
				free(str[i][j]);
			j++;
		}
		free(str[i]);
		i--;
	}
	std_errors("Failed to allocate memory for args");
	free(str);
}

void	free_cmd_path(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_arr(char **str, int i)
{
	if (!str)
		return ;
	while (i >= 0)
	{
		if (str[i])
			free(str[i]);
		i--;
	}
	free(str);
}

void	ft_clean_up(int fd[2], t_pip *pip)
{
	if (!pip)
		return ;
	if (pip->cmd_args)
		free_args(pip->cmd_args);
	if (pip->cmd_path)
		free_cmd_path(pip->cmd_path);
	if (pip->here_doc == TRUE)
	{
		if (fd[0] != -1)
			close(fd[0]);
		if (fd[1] != -1)
			close(fd[1]);
	}
	free(pip);
}
