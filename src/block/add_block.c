/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:54:24 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 11:05:25 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "block.h"

void	add_block(char *start, char *end)
{
	t_block	*aux;

	if (!(*get_instance_block()))
		(*get_instance_block()) = create_block(start, end);
	else
	{
		aux = (*get_instance_block());
		while (aux->next)
			aux = aux->next;
		aux->next = create_block(start, end);
	}
}
