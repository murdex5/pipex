/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:39:25 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/31 13:39:26 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	free_two_vals(char **arr1, char **arr2, int i, char **path)
{
	if (arr1 != NULL)
		free_arr(arr1, i - 2);
	if (arr2 != NULL)
		free_cmd_path(arr2);
	if (path != NULL)
		free_cmd_path(path);
	std_errors("Memory allocation failed");
	return (1);
}

int	std_errors(char *msg)
{
	ft_putstr_fd("Pipex: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	std_error_free(int fd[2], t_pip *pip, char *msg)
{
	ft_clean_up(fd, pip);
	if (msg)
		std_errors(msg);
	return (0);
}

int	err_p(char *msg)
{
	perror(msg);
	exit(1);
}
