/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 18:44:38 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 19:55:12 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_array.h"

# define SCORE_MAX 2000000000

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				c_score;
	int				*ants;
	int				turn;
	t_array			link;
}					t_room;

typedef struct		s_data
{
	t_room			*start;
	t_room			*end;
	int				room_nbr;
	int				ants;
	int				nb_turnmax;
	int				**ends;
	int				ant;
	t_array			pos;
	t_array			rooms;
}					t_data;

typedef struct		s_parse
{
	int				ants;
	int				is_start;
	int				is_end;
	t_room			*start;
	t_room			*end;
	t_array			rooms;
	t_array			tubs;
}					t_parse;

int					parse(t_data *d);
int					is_start(char *str);
int					is_end(char *str);
int					is_room(char *str);
int					is_tub(char *str);
int					is_comment(char *str);
int					is_cmd(char *str);
int					is_ants(char *str);
void				handle_error(t_parse *p);
void				print_parse(t_parse *p);

int					handle_cmd_room(char *line, t_parse *p);
int					handle_cmd(char *line, t_parse *p);

t_room				*new_room_named(char *str);
int					link_rooms(t_parse *p);
void				free_room(t_room *r);

void				free_parse(t_parse *p);
void				free_data(t_data *d);
#endif
