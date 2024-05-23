/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:22:09 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 13:53:06 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "libft.h"
#include "block/command/redirection.h"

static int	get_type(char **ref)
{
	if ((**ref) == '>')
	{
		(*ref)++;
		if ((**ref) == '>')
		{
			(*ref)++;
			return (TYPE_WRITE_APPEND);
		}
		else
			return (TYPE_WRITE);
	}
	else
	{
		(*ref)++;
		if ((**ref) == '<')
		{
			(*ref)++;
			return (TYPE_HERE_DOC);
		}
		else
			return (TYPE_READ);
	}
}

static char	*get_arg(char **ref)
{
	char	aux;
	char	*arg;
	char	*start;

	start = (*ref);
	skip_quotes(ref);
	while ((**ref) && (**ref) != ' ' && (**ref) != '>'
		&& (**ref) != '<' && (**ref) != '|')
		(*ref)++;
	aux = (**ref);
	(**ref) = '\0';
	arg = ft_strdup(start);
	(**ref) = aux;
	return (arg);
}

t_redirection	*create_redirection(char **ref)
{
	t_redirection	*new_redirection;

	new_redirection = (t_redirection *)ft_calloc(1, sizeof(t_redirection));
	new_redirection->type = get_type(ref);
	while ((**ref) == ' ')
		(*ref)++;
	new_redirection->arg = get_arg(ref);
	return (new_redirection);
}
