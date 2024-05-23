/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:05:11 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/14 21:35:44 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "block/command.h"

static t_command	*init_command(void)
{
	t_command	*new_command;

	new_command = (t_command *)ft_calloc(1, sizeof(t_command));
	new_command->fds.in = -1;
	new_command->fds.out = -1;
	new_command->fds.err = -1;
	new_command->is_home = FALSE;
	new_command->argv = (char **)ft_creatematrix(sizeof(char *));
	return (new_command);
}

t_command	*create_command(char *start, char *end)
{
	t_command	*new_command;

	new_command = init_command();
	while (start < end)
	{
		if ((*start) == '>' || (*start) == '<')
			add_redirection(new_command, &start);
		else if ((*start) != ' ')
			add_argument(new_command, &start);
		while ((*start) == ' ')
			start++;
	}
	return (new_command);
}
