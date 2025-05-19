/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:47:51 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/01 15:47:54 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_ac(int ac)
{
	if (ac < 5)
		return (std_errors("./pipex infile cmd1 cmd2 outfile"), 0);
	return (1);
}

t_bool	check_here_doc(char **argv)
{
	if (argv[1] && ft_strncmp("here_doc", argv[1], ft_strlen(argv[1])) == 0)
		return (TRUE);
	return (FALSE);
}

static int	open_here_doc(int fd[2], int argc, char **argv)
{
	char	*line;

	fd[0] = open(".here_doc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd[0] < 0)
		return (perror("Failed to open .here_doc_tmp"), 0);
	while (1)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
		if (!line)
			return (std_errors("Memory allocation for line failed"), 0);
		if (!check_strs(argv[2], line))
			break ;
		ft_putstr_fd(line, fd[0]);
		free(line);
	}
	close(fd[0]);
	fd[0] = open(".here_doc_tmp", O_RDONLY);
	if (fd[0] < 0)
		return (perror("Failed to reopen .here_doc_tmp"), 0);
	fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd[1] < 0)
		return (perror("Failed to reopen .here_doc_tmp"), 0);
	return (1);
}

static int	open_regular(int fd[2], int argc, char **argv)
{
	if (ft_strcmp(argv[1], "/dev/urandom") == 0)
	{
		fd[0] = open("/dev/urandom", O_RDONLY);
		if (fd[0] == -1)
			return (err_p("Cannot open /dev/urandom"));
	}
	else
	{
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] == -1)
			fd[0] = -1;
	}
	fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] == -1)
	{
		if (fd[0] != -1)
			close(fd[0]);
		perror("outputfile: ");
		fd[1] = -2;
		return (0);
	}
	return (1);
}

int	check_args(int fd[2], int argc, char **argv, t_bool here_doc)
{
	if (here_doc == TRUE && argc < 6)
		return (err_p("here_doc requires 6 arguments"));
	if (here_doc == FALSE && argc < 5)
		return (err_p("Too few arguments"));
	if (here_doc == TRUE)
	{
		if (!open_here_doc(fd, argc, argv))
			return (0);
	}
	else
	{
		if (!open_regular(fd, argc, argv))
			return (0);
	}
	return (1);
}
