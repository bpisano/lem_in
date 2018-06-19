/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   room_manager.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/16 13:19:07 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/18 19:38:39 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

/*
 ** Init a new t_room with a given room data line.
*/

t_room	*new_room_named(char *str)
{
	int		i;
	t_room	*new;

	i = -1;
	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	while (ft_isalnum(str[++i]))
		;
	new->name = ft_strsub(str, 0, i);
	new->x = 0;
	new->y = 0;
	new->ants = 0;
	new->turn = SCORE_MAX;
	new->c_score = SCORE_MAX;
	ar_init(&(new->link), 1);
	return (new);
}

/*
 ** Return the room with a given name.
 ** If there is no room, it returns NULL.
*/

static t_room	*room_named(t_array rooms, char *name)
{
	int		i;

	i = -1;
	(void)name;
	while (rooms[++i])
		if (ft_strcmp(((t_room *)rooms[i])->name, name) == 0)
			return ((t_room *)rooms[i]);
	return (NULL);
}


/*
 ** Fetch the 2 rooms in pointers with a given data line
 ** Return 1 the rooms have been found else 0.
*/

static int		get_link_rooms(char *line, t_parse *p, t_room **r1, t_room **r2)
{
	char	*n1;
	char	*n2;
	char	**split;

	split = ft_strsplit(line, '-');
	n1 = split[0];
	n2 = split[1];
	if (!(*r1 = room_named(p->rooms, n1)))
	{
		free(n1);
		free(n2);
		free(split);
		return (0);
	}
	if (!(*r2 = room_named(p->rooms, n2)))
	{
		free(n1);
		free(n2);
		free(split);
		return (0);
	}
	free(split);
	return (1);
}

/*
 ** Link 2 t_room with a given tub data line and the parsed data.
*/

int				link_rooms(t_parse *p)
{
	int		i;
	t_room	*r1;
	t_room	*r2;

	i = -1;
	while (p->tubs[++i])
	{
		if (!get_link_rooms(p->tubs[i], p, &r1, &r2))
			return (0);
		ar_append(&(r1->link), r2);
		ar_append(&(r2->link), r1);
	}
	return (1);
}
