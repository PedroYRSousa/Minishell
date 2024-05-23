/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 06:22:50 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 09:56:09 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	skip_double_quotes(char **input)
{
	char	*aux;

	if ((**input) == '\"')
	{
		aux = ft_strchr(((*input) + 1), (**input));
		if (aux)
			(*input) = (aux);
		(*input)++;
	}
}

void	skip_single_quotes(char **input)
{
	char	*aux;

	if ((**input) == '\'')
	{
		aux = ft_strchr(((*input) + 1), (**input));
		if (aux)
			(*input) = (aux);
		(*input)++;
	}
}

void	skip_quotes(char **input)
{
	skip_single_quotes(input);
	skip_double_quotes(input);
}
