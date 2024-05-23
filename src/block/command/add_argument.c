/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:08:12 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 14:01:59 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "libft.h"
#include "block/command.h"

void	add_argument(t_command *command, char **ref)
{
	char	aux;
	char	*start;

	start = (*ref);
	while ((**ref) && (**ref) != ' ' && (**ref) != '<'
		&& (**ref) != '>' && (**ref) != '|')
	{
		skip_quotes(ref);
		if ((**ref) && (**ref) != ' ' && (**ref) != '<'
			&& (**ref) != '>' && (**ref) != '|')
			(*ref)++;
	}
	aux = (**ref);
	(**ref) = '\0';
	command->argv
		= (char **)ft_addmatrix((void **)command->argv, (void *)start);
	(**ref) = aux;
}
