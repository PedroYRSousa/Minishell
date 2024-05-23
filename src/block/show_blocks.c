/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_blocks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:15:07 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/05 13:41:16 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "block.h"
#include <stdio.h>

static void	show_redirections(t_redirection *reds)
{
	int	index;

	while (reds)
	{
		if (reds->type == TYPE_WRITE)
			printf(">");
		if (reds->type == TYPE_WRITE_APPEND)
			printf(">>");
		if (reds->type == TYPE_READ)
			printf("<");
		if (reds->type == TYPE_HERE_DOC)
			printf("<<");
		printf(" ARG %s\n", reds->arg);
		printf(" TMP \n");
		index = 0;
		while (reds->tmp && reds->tmp[index])
		{
			printf("%s\n", reds->tmp[index]);
			index++;
		}
		reds = reds->next;
	}
}

static void	show_command(t_command *command)
{
	int	index;

	index = 0;
	printf("===== COMMAND =====\n");
	printf("IN (%d) OUT (%d) ERR (%d)\n",
		command->fds.in, command->fds.out, command->fds.err);
	while (command->argv[index])
	{
		printf("%s\n", command->argv[index]);
		index++;
	}
	show_redirections(command->redirections);
}

void	show_blocks(void)
{
	t_block	*blocks;

	blocks = (*get_instance_block());
	while (blocks)
	{
		show_command(blocks->command);
		blocks = blocks->next;
	}
}
