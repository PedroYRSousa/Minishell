/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:41:53 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 12:46:39 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "block/command.h"

void	add_redirection(t_command *command, char **ref)
{
	t_redirection	*aux;

	if (!command->redirections)
		command->redirections = create_redirection(ref);
	else
	{
		aux = command->redirections;
		while (aux->next)
			aux = aux->next;
		aux->next = create_redirection(ref);
	}
}
