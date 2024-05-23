/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:36:25 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/02/03 04:42:38 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Compares 's1' and 's2', 'n' times.
 *  \ Compara 's1' e 's2', 'n' vezes.
 * 
 * @param s1 Reference to be verified.
 *  \ Referência a ser verificada.
 * @param s2 Reference to be verified.
 *  \ Referência a ser verificada.
 * @param n Number of bytes to be verified.
 *  \ Quantidade de bytes a ser verificada.
 * @return If equal returns, otherwise it will be the difference
 *  between 's1' and 's2'.
 *  \ Se igual retorna, se não sera a diferença entre 's1' e 's2'.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*_s1;
	const char	*_s2;

	_s1 = (const char *)s1;
	_s2 = (const char *)s2;
	while (n-- > 0)
	{
		if (*_s1 != *_s2)
			return ((unsigned char)*_s1 - (unsigned char)*_s2);
		_s1++;
		_s2++;
	}
	return (0);
}
