/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:45:24 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 09:54:50 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "libft.h"
#include "ms_error.h"

static char	valid_pipe(char **input);
static char	valid_redirections(char **input);

char	syntax(char *input)
{
	while ((*input) == ' ')
		input++;
	if ((*input) == '|')
	{
		show_error_syntax('|');
		return (FALSE);
	}
	while ((*input))
	{
		if (!valid_redirections(&input) || !valid_pipe(&input))
		{
			show_error_syntax((*input));
			return (FALSE);
		}
		skip_quotes(&input);
		if ((*input))
			input++;
	}
	return (TRUE);
}

static char	valid_pipe(char **input)
{
	skip_quotes(input);
	if ((**input) == '|')
	{
		(*input)++;
		while ((**input) == ' ')
			(*input)++;
		if ((**input) == '|' || (**input) == '\n' || (**input) == '\0')
			return (FALSE);
	}
	return (TRUE);
}

static char	valid_redirections(char **input)
{
	skip_quotes(input);
	if ((**input) == '<' || (**input) == '>')
	{
		if (((**input) == '<' && (*(*input + 1)) == '<')
			|| ((**input) == '>' && (*(*input + 1)) == '>'))
			(*input)++;
		(*input)++;
		while ((**input) == ' ')
			(*input)++;
		if ((**input) == '<' || (**input) == '>'
			|| (**input) == '|' || (**input) == '\n'
			|| (**input) == '\0')
			return (FALSE);
	}
	return (TRUE);
}
