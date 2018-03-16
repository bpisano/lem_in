/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   room_manager.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/16 13:19:07 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 14:01:34 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem-in.h"

t_room	new_room(char *str)
{
	int		i;
	t_room	new;

	i = -1;
	while (ft_is_alpha(str[++i]));
	new.name = ft_strsub(str, i);
	new.x = 0;
	new.y = 0;
	new.score = SCORE_MAX;
	return (new);
}

void	free_room(t_room *room)
{
	free(room->name);
}
