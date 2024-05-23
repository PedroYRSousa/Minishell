/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:15:25 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/02/03 04:28:19 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Scan 'n' bytes of 's' until it finds 'c'.
 *  \ Escaneia 'n' bytes de 's' ate encontrar 'c'.
 * 
 * @param s The reference to be scanned.
 *  \ A referencia para ser escaneada.
 * @param c The reference that must be found.
 *  \ A referência que deve ser encontrada.
 * @param n Number of bytes to be verified.
 *  \ Quantidade de bytes a ser verificada.
 * @return Returns 's' if found 'c'. If not, return NULL.
 *  \ Retorna 's' se encontrar 'c'. Se não retorna NULL.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;

	str = (const char *)s;
	while (n-- > 0)
	{
		if (*str == (c % 256))
			return ((void *)(str));
		else
			str++;
	}
	return (NULL);
}
