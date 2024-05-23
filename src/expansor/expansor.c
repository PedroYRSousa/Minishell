/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:19:40 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/15 09:43:27 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "info.h"
#include "libft.h"
#include "block.h"

static char	*get_name(char *start)
{
	char	aux;
	char	*end;
	char	*name;

	end = start;
	end++;
	if ((*end) == '\0')
		return (NULL);
	if ((*end) == '$')
		end++;
	else
	{
		while ((*end) && (*end) != ' ' && (*end) != '$'
			&& (*end) != '\"' && (*end) != '\'')
			end++;
	}
	aux = (*end);
	(*end) = '\0';
	name = ft_strdup(start);
	(*end) = aux;
	return (name);
}

static char	*replace_value(t_command *com, char **string, char *name)
{
	char	*value;
	char	*aux_string;

	value = get_env(name);
	aux_string = ft_replace((*string), name, value);
	free((*string));
	(*string) = aux_string;
	if (ft_strcmp(name, "$HOME") == 0)
		com->is_home = TRUE;
	free(name);
	return (*string);
}

static void	resolve_string(t_command *com, char **string)
{
	char	*aux;
	char	*name;
	char	in_double_quotes;

	aux = (*string);
	in_double_quotes = FALSE;
	while (aux && (*aux))
	{
		if ((*aux) == '\"')
			in_double_quotes = !in_double_quotes;
		if (!in_double_quotes)
			skip_single_quotes(&aux);
		if ((*aux) == '$')
		{
			name = get_name(aux);
			if (name)
				aux = replace_value(com, string, name);
			else
				aux++;
		}
		else
			aux++;
	}
	remove_quotes(string);
}

static void	resolve_command(t_command *com)
{
	t_redirection	*aux;
	int				index;

	index = 0;
	while (com->argv[index])
	{
		resolve_string(com, &(com->argv[index]));
		index++;
	}
	aux = com->redirections;
	while (aux)
	{
		resolve_string(com, &(aux->arg));
		index = 0;
		while (aux->tmp && aux->tmp[index])
		{
			resolve_string(com, &(aux->tmp[index]));
			index++;
		}
		aux = aux->next;
	}
}

void	expansor(void)
{
	t_block	*blocks;

	blocks = (*get_instance_block());
	while (blocks && !get_instance_info()->canceled)
	{
		resolve_command(blocks->command);
		blocks = blocks->next;
	}
}
