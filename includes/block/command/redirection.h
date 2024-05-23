/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:47:07 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/05 05:57:34 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# ifndef TYPE_WRITE
#  define TYPE_WRITE 00
# endif

# ifndef TYPE_WRITE_APPEND
#  define TYPE_WRITE_APPEND 01
# endif

# ifndef TYPE_READ
#  define TYPE_READ 02
# endif

# ifndef TYPE_HERE_DOC
#  define TYPE_HERE_DOC 03
# endif

typedef struct s_redirection
{
	int						type;
	char					*arg;
	char					**tmp;
	struct s_redirection	*next;
}	t_redirection;

t_redirection	*create_redirection(char **ref);

#endif