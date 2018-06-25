/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   data_manager.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/25 16:51:18 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 18:21:46 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	free_data(t_data *d)
{
	int		i;
	t_room	*room;

	i = -1;
	while (d->rooms[++i])
	{
		room = (t_room *)(d->rooms[i]);
		free_room(room);
	}
	i = -1;
	while (++i < d->nb_turnmax)
		free(d->ends[i]);
	free(d->ends);
	free(d->pos);
	free(d->rooms);
}

void	free_parse(t_parse *p)
{
	int		i;

	i = -1;
	while (p->tubs[++i])
		free(p->tubs[i]);
	free(p->tubs);
}
