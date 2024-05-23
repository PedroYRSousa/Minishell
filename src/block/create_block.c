/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:54:24 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 13:25:54 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "block.h"

t_block	*create_block(char *start, char *end)
{
	t_block	*new_block;

	new_block = (t_block *)ft_calloc(1, sizeof(t_block));
	new_block->command = create_command(start, end);
	return (new_block);
}
