/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:15:42 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/02/03 04:22:28 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Copies 'n' bytes from 'src' to 'dest', stopping if it encounters 'c'.
 *  \ Copia 'n' bytes de 'src' para 'dest', parando se encontrar 'c'.
 * 
 * @param dest The location where the bytes will be copied.
 *  \ O local para onde sera copiado os bytes..
 * @param src The source of the bytes.
 *  \ A origem dos bytes.
 * @param c The stop character.
 *  \ O caractere de parada.
 * @param n Amount of bytes.
 *  \ Quantidade de bytes.
 * @return The function returns 'dest', if it doesn't find 'c' it returns NULL.
 *  \ A função retorna 'dest', se não encontrar 'c' retorna NULL.
 */
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*_src;
	unsigned char	*_dest;

	_src = (unsigned char *)src;
	_dest = (unsigned char *)dest;
	while (n-- > 0)
	{
		*(_dest++) = *_src;
		if (*_src == (unsigned char)c)
			return (_dest);
		_src++;
	}
	return (NULL);
}
