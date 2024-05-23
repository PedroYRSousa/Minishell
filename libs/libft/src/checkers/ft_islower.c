/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:02:15 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/02/15 14:16:03 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Checks if 'c' is an lowercase character.
 *  \ Verifica se 'c' é um caractere minúsculo.
 * 
 * @param c The variable to be checked. \ A variavel a ser verificada.
 * @return If true it will return TRUE (1), if not FALSE (0).
 *  \ Se verdadeiro retornará TRUE (1), se não FALSE (0).
 */
int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
