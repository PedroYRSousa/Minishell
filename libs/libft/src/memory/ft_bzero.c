/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 10:59:52 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/02/03 05:32:49 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Fills 'n' memory positions pointed to by 's' with NULL.
 *  \ Preenche 'n' posições da memoria apontadas por 's' com NULL.
 * 
 * @param s The variable that points to the beginning of the address.
 *  \ A variavel que aponta para o começo do endereço.
 * @param n The variable with the count of addresses to be filled.
 *  \ A variavel com a contagem de endereços a serem preenchidos.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
