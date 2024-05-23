/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error_syntax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:34:55 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/05 17:34:57 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	show_error_syntax(char token)
{
	char	*default_msg;

	default_msg = "minishell: syntax error near unexpected token `";
	ft_putstr_fd(default_msg, STDERR_FILENO);
	if (token == '\n' || token == '\0')
		ft_putstr_fd("newline", STDERR_FILENO);
	else
		ft_putchar_fd(token, STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
}
