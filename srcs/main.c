/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:47:28 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/01 15:47:32 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	check_state(int out_fd, int out_filefaidd)
{
	if (out_filefaidd == -2)
		return (1);
	return (out_fd);
}

int	main(int argc, char **argv, char *envp[])
{
	t_pip	*pip;
	int		status;
	int		fd[2];
	int		out_fd[2];
	int		state;

	if (!check_ac(argc))
		return (EXIT_FAILURE);
	status = 0;
	pip = populate_pip(out_fd, argc, argv, envp);
	if (!pip)
	{
		open_otfile_if_failed(out_fd[1], argv[argc - 1]);
		state = check_state(out_fd[0], out_fd[1]);
		close_fd(out_fd[0], out_fd[1]);
		ft_clean_up(fd, pip);
		return (state);
	}
	status = ft_exec(fd, pip, pip->cmd_path, out_fd);
	if (pip->here_doc == TRUE)
		unlink(".here_doc_tmp");
	ft_clean_up(fd, pip);
	close_fd(out_fd[0], out_fd[1]);
	return (status);
}
