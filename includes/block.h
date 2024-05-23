/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:47:07 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/05 13:42:19 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_H
# define BLOCK_H

# include "block/command.h"

typedef struct s_block
{
	t_command		*command;
	char			is_valid;
	struct s_block	*next;
}	t_block;

void	show_blocks(void);
void	clear_blocks(void);
t_block	**get_instance_block(void);
void	add_block(char *start, char *end);
t_block	*create_block(char *start, char *end);

#endif