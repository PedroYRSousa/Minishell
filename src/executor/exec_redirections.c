/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:46:47 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/05 17:44:51 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "libft.h"
#include "block.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

static char	exec_read(char *file, int *fd)
{
	if ((*fd) != -1)
		close((*fd));
	(*fd) = open(file, O_RDONLY);
	if ((*fd) < 0)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		perror(file);
		return (FALSE);
	}
	return (TRUE);
}

static void	exec_write(char *file, int flags, int *fd)
{
	if ((*fd) != -1)
		close((*fd));
	(*fd) = open(file, flags, 0666);
}

static void	exec_here_doc(char **lines, int *fd)
{
	int	index;
	int	_pipe[2];

	if ((*fd) != -1)
		close((*fd));
	pipe(_pipe);
	index = 0;
	while (lines[index])
	{
		ft_putstr_fd(lines[index], _pipe[1]);
		if (lines[index + 1])
			ft_putstr_fd("\n", _pipe[1]);
		index++;
	}
	close(_pipe[1]);
	(*fd) = _pipe[0];
}

static void	exec(t_block *block)
{
	t_command		*com;
	t_redirection	*reds;

	com = block->command;
	reds = com->redirections;
	while (reds && block->is_valid)
	{
		if (reds->type == TYPE_HERE_DOC)
			exec_here_doc(reds->tmp, &(com->fds.in));
		if (reds->type == TYPE_READ)
		block->is_valid = exec_read(reds->arg, &(com->fds.in));
		if (reds->type == TYPE_WRITE)
			exec_write(reds->arg,
				O_CREAT | O_TRUNC | O_WRONLY, &(com->fds.out));
		if (reds->type == TYPE_WRITE_APPEND)
			exec_write(reds->arg,
				O_CREAT | O_APPEND | O_WRONLY, &(com->fds.out));
		reds = reds->next;
	}
}

void	exec_redirections(void)
{
	int		_pipe[2];
	t_block	*blocks;

	blocks = (*get_instance_block());
	while (blocks && !get_instance_info()->canceled)
	{
		blocks->is_valid = TRUE;
		if (blocks->next)
		{
			pipe(_pipe);
			blocks->command->fds.out = _pipe[1];
			blocks->next->command->fds.in = _pipe[0];
		}
		exec(blocks);
		if (blocks->next && !blocks->is_valid)
		{
			close(blocks->next->command->fds.in);
			blocks->next->command->fds.in = -1;
		}
		blocks = blocks->next;
	}
}
