/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:02:15 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/02/03 04:07:49 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Checks if 'c' is a printable character.
 *  \ Verifica se 'c' é um caractere imprimivel.
 * 
 * @param c The variable to be checked. \ A variavel a ser verificada.
 * @return If true it will return TRUE (1), if not FALSE (0).
 *  \ Se verdadeiro retornará TRUE (1), se não FALSE (0).
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
