/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:57:17 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 09:04:48 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# ifndef PATH
#  define PATH "PATH"
# endif

# ifndef MS_PATH
#  define MS_PATH "MS_PATH"
# endif

# include "util.h"

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

void	clear_env(void);
char	**get_envs(void);
char	*get_env(char *name);
void	unset_env(char *name);
t_env	**get_instance_env(void);
void	remove_env(t_env *target);
void	load_env(int argc, char **argv, char **envp);

void	set_env(char *name, char *value);
void	add_env(char *name, char *value);
t_env	*create_env(char *name, char *value);

#endif