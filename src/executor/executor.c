/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:57:45 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/15 10:57:45 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "info.h"
#include "libft.h"
#include "block.h"
#include "ms_error.h"
#include "executor.h"
#include <sys/wait.h>

static void	exec(t_command *com)
{
	char	**envp;
	int		result;
	int		wstatus;
	char	*c_wstatus;

	wstatus = 0;
	envp = get_envs();
	if (fork() == 0)
	{
		result = execve(com->argv[0], com->argv, envp);
		if (result != 0)
		{
			show_error_execve(com->argv[0]);
			exit(result);
		}
	}
	wait(&wstatus);
	c_wstatus = ft_itoa(WEXITSTATUS(wstatus));
	set_env("?", c_wstatus);
	free(c_wstatus);
	ft_clear_matrix((void ***)&envp);
}

static void	prepare(t_command *com)
{
	if (com->fds.in > 0)
	{
		dup2(com->fds.in, STDIN_FILENO);
		close(com->fds.in);
	}
	if (com->fds.out > 0)
	{
		dup2(com->fds.out, STDOUT_FILENO);
		close(com->fds.out);
	}
}

static void	define_command(t_command *com)
{
	char	*name;

	prepare(com);
	name = (*com->argv);
	if (ft_strcmp(name, "exit") == 0)
		ms_exit(com);
	else if (ft_strcmp(name, "cd") == 0)
		ms_cd(com);
	else if (ft_strcmp(name, "export") == 0)
		ms_export(com);
	else if (ft_strcmp(name, "unset") == 0)
		ms_unset(com);
	else
		exec(com);
	reset_fds();
}

void	executor(void)
{
	t_block	*blocks;

	blocks = (*get_instance_block());
	while (blocks)
	{
		if (blocks->is_valid)
			define_command(blocks->command);
		blocks = blocks->next;
	}
}
