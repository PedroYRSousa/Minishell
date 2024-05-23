/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearmatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:40:59 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/02/18 06:12:30 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_matrix(void ***matrix)
{
	size_t	size;
	size_t	index;

	if (!matrix)
		return ;
	size = ft_count_matrix((*matrix));
	index = 0;
	while (index < size)
	{
		free ((*matrix)[index]);
		index++;
	}
	free ((*matrix)[index]);
	free ((*matrix));
	(*matrix) = NULL;
}
