/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:47:07 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/09 10:37:16 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

void	remove_quotes(char **src);
void	skip_quotes(char **input);
void	skip_double_quotes(char **input);
void	skip_single_quotes(char **input);

#endif