/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_blocks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:53:39 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/05 05:59:32 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "block.h"
#include <unistd.h> 

static void	clear_redirection(t_redirection *reds)
{
	t_redirection	*aux;

	while (reds)
	{
		aux = reds;
		reds = reds->next;
		if (aux->tmp)
			ft_clear_matrix((void ***)&(aux->tmp));
		free(aux->arg);
		free(aux);
	}
}

static void	clear_command(t_command *command)
{
	if (command->fds.in > 0)
		close(command->fds.in);
	if (command->fds.out > 0)
		close(command->fds.out);
	if (command->fds.err > 0)
		close(command->fds.err);
	ft_clear_matrix((void ***)&command->argv);
	clear_redirection(command->redirections);
	command->redirections = NULL;
	free(command);
}

void	clear_blocks(void)
{
	t_block	*aux;

	while ((*get_instance_block()))
	{
		aux = (*get_instance_block());
		(*get_instance_block()) = (*get_instance_block())->next;
		clear_command(aux->command);
		aux->command = NULL;
		free(aux);
	}
}
