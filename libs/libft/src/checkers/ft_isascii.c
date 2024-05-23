/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:02:15 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/02/03 04:06:11 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Checks if 'c' is in the ASCII table value set.
 *  \ Verifica se 'c' esta no conjunto de valores da tabela ASCII.
 * 
 * @param c The variable to be checked. \ A variavel a ser verificada.
 * @return If true it will return TRUE (1), if not FALSE (0).
 *  \ Se verdadeiro retornará TRUE (1), se não FALSE (0).
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
