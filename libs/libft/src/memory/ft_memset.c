/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:00:01 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/02/03 04:42:01 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Determines 'n' bytes of 's' with 'c'.
 *  \ Determina 'n' bytes de 's' com 'c'.
 * 
 * @param s Reference to insert the bytes.
 *  \ Referência a ser inserido os bytes.
 * @param c Reference to be inserted.
 *  \ Referência a ser inserida.
 * @param n Number of bytes to be inserted.
 *  \ Quantidade de bytes a ser inserido.
 * @return Returns the reference of 's'.
 *  \ Retorna a referência de 's'.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n-- > 0)
		*(str++) = (c % 256);
	return (s);
}
