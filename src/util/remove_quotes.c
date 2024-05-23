/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 06:22:50 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/09 12:14:21 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reset_steps(char **aux, size_t steps)
{
	while (steps > 0)
	{
		(*aux)++;
		steps--;
	}
}

static void	remove_quote(char **src, char **aux, size_t steps, char *target)
{
	char	*_aux;

	_aux = ft_nreplace((*src), target, "", steps);
	free((*src));
	(*src) = _aux;
	(*aux) = (*src);
	reset_steps(aux, steps);
}

static void	__remove_quotes(char **src, char in_d_quotes, char in_s_quotes)
{
	char	*aux;
	size_t	steps;

	steps = 0;
	aux = (*src);
	while ((*aux))
	{
		if ((*aux) == '\'' && !in_d_quotes)
		{
			remove_quote(src, &aux, steps, "\'");
			in_s_quotes = !in_s_quotes;
		}
		else if ((*aux) == '\"' && !in_s_quotes)
		{
			remove_quote(src, &aux, steps, "\"");
			in_d_quotes = !in_d_quotes;
		}
		else if ((*aux))
		{
			aux++;
			steps++;
		}
	}
}

void	remove_quotes(char **src)
{
	__remove_quotes(src, FALSE, FALSE);
}
