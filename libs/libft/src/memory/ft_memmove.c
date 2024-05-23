/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:15:42 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/02/03 04:39:24 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Copy 'n' bytes from 'src' to 'dest'.
 *  \ Cópia 'n' bytes de 'src' para 'dest'.
 * 
 * @param dest Reference to insert the bytes.
 *  \ Referência a ser inserido os bytes.
 * @param src Source byte reference.
 *  \ Referência fonte dos bytes.
 * @param n Number of bytes to be copied.
 *  \ Quantidade de bytes a ser copiada.
 * @return Returns the reference of 'dest'.
 *  \ Retorna a referência de 'dest'.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*_dest;
	const char	*_src;

	_dest = (char *)dest;
	_src = (const char *)src;
	if (_dest == _src)
		return (_dest);
	if (_dest > _src)
	{
		while (n-- > 0)
			*(_dest + n) = *(_src + n);
	}
	else
	{
		while (n-- > 0)
			*(_dest++) = *(_src++);
	}
	return (dest);
}
