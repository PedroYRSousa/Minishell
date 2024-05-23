/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 05:21:32 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/05 17:33:39 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "libft.h"
#include "block.h"
#include "ms_error.h"
#include <stdio.h>
#include <signal.h>
#include <readline/readline.h>

static void	exec(t_redirection *red)
{
	char	*input;

	red->tmp = (char **)ft_creatematrix(sizeof(char *));
	while (!get_instance_info()->canceled)
	{
		input = readline("> ");
		if (input)
		{
			if (ft_strcmp(input, red->arg) == 0)
			{
				free(input);
				break ;
			}
			red->tmp = (char **)ft_addmatrix((void **)red->tmp, (void *)input);
			free(input);
		}
		else if (!get_instance_info()->canceled)
		{
			show_warning_here_doc(ft_count_matrix((void **)red->tmp), red->arg);
			break ;
		}
	}
}

static void	get_here_doc(t_redirection *reds)
{
	while (reds && !get_instance_info()->canceled)
	{
		if (reds->type == TYPE_HERE_DOC)
			exec(reds);
		reds = reds->next;
	}
}

static void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		get_instance_info()->canceled = TRUE;
		close(STDIN_FILENO);
	}
}

void	exec_here_doc(void)
{
	t_block	*blocks;

	signal(SIGINT, handle_signal);
	blocks = (*get_instance_block());
	while (blocks && !get_instance_info()->canceled)
	{
		get_here_doc(blocks->command->redirections);
		blocks = blocks->next;
	}
}
