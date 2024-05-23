/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:50:17 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/01 17:07:54 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_addmatrix(void **matrix, void *line)
{
	size_t	index;
	void	**aux;

	aux = matrix;
	matrix = (void **)ft_calloc((ft_count_matrix(matrix) + 2), sizeof(void *));
	index = 0;
	while (aux[index])
	{
		matrix[index] = aux[index];
		index++;
	}
	free(aux);
	matrix[index] = ft_strdup(line);
	return (matrix);
}
