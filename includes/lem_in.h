/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem-in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 18:44:38 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 20:14:03 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

# define MALLCHECK(x) if (!x) return ;
# define MALLRET(x) if (!x) return (0);
# define SCORE_MAX 2000000000

typedef void 		**ft_array;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				score;
	char			ants;
	ft_array		link;
}					t_room;

typedef struct		s_data
{
	t_room			*start;
	t_room			*end;
	int				room_nbr;
	int				ants;
}					t_data;

int					ar_init(ft_array *array, size_t size);
int					ar_free(ft_array *array);
int					ar_count(ft_array array);
int					ar_append(ft_array *array, void *value);

void				parse_data(t_data *d);
int					is_room(char *str);
int					is_tub(char *str);
int					is_comment(char *str);
int					is_command(char *str);
int					is_ants(char *str);

t_room				*new_room(char *str);
t_room				*room_named(ft_array array, char *name);

#endif
