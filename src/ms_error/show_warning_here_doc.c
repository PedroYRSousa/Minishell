/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_warning_here_doc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:31:09 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/05 17:35:07 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	show_warning_here_doc(int count_lines, char *eof)
{
	ft_putstr_fd("minishell: warning: here-document at line ",
		STDERR_FILENO);
	ft_putnbr_fd(count_lines, STDERR_FILENO);
	ft_putstr_fd(" delimited by end-of-file (wanted `", STDERR_FILENO);
	ft_putstr_fd(eof, STDERR_FILENO);
	ft_putendl_fd("\')", STDERR_FILENO);
}
