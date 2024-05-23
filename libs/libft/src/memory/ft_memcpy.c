/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:15:42 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/02/03 04:37:44 by pyago_ra         ###   ########.fr       */
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
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*_src;
	char		*_dest;

	if (dest == src)
		return (dest);
	_src = (const char *)src;
	_dest = (char *)dest;
	while (n-- > 0)
		*(_dest++) = *(_src++);
	return (dest);
}
