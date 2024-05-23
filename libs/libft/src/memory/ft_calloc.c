/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:04:45 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/02/03 04:15:46 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Allocates 'nmemb' * 'size', initializing them to NULL.
 *  \ Aloca 'nmemb' * 'size', inicializando-os com NULL.
 * 
 * @param nmemb The amount of spaces.
 *  \ A quantidade de espaços.
 * @param size The size of spaces.
 *  \ O tamanho dos espaços.
 * @return The reference to the allocated memory.
 *  \ A referencia para a memoria alocada.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*output;

	output = malloc(nmemb * size);
	if (output)
		ft_bzero(output, nmemb * size);
	return (output);
}
