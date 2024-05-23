/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:48:43 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/15 09:14:16 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "block.h"

void	parser(char *input)
{
	char	*start;

	while ((*input) == ' ')
		input++;
	start = input;
	if (!(*input))
		return ;
	while ((*input))
	{
		skip_quotes(&input);
		if ((*input) == '|')
		{
			add_block(start, input);
			start = input + 1;
		}
		if ((*input))
			input++;
	}
	add_block(start, input);
}
