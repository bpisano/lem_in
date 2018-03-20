/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   room_manager.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/16 13:19:07 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 20:13:24 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*new_room(char *str)
{
	int		i;
	t_room	*new;

	i = -1;
	MALLRET((new = (t_room *)malloc(sizeof(t_room))));
	while (ft_isalnum(str[++i]))
		;
	new->name = ft_strsub(str, 0, i);
	new->x = 0;
	new->y = 0;
	new->score = SCORE_MAX;
	new->ants = 0;
	ar_init(&(new->link), 1);
	return (new);
}

void	free_room(t_room *room)
{
	free(room->name);
}

t_room	*room_named(ft_array array, char *name)
{
	int		i;

	i = -1;
	while (array[++i])
	{
		if (!ft_strcmp(((t_room *)array[i])->name, name))
			return ((t_room *)array[i]);
	}
	return (NULL);
}
