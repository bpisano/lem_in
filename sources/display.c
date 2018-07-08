/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/08 19:38:28 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/08 20:23:00 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

/*
 ** Free the parsing data and display an error message.
*/

void	handle_error(t_parse *p)
{
	free(p->rooms);
	free(p->tubs);
	ft_putstr("ERROR\n");
}

void	print_parse(t_parse *p)
{
	int		i;
	t_room	*start;
	t_room	*end;
	t_room	*room;

	i = -1;
	ft_printf("%d\n", p->ants);
	start = (t_room *)p->start;
	ft_printf("##start\n");
	ft_printf("%s %d %d\n", start->name, start->x, start->y);
	end = (t_room *)p->end;
	ft_printf("##end\n");
	ft_printf("%s %d %d\n", end->name, end->x, end->y);
	while ((room = (t_room *)(p->rooms[++i])))
		if (ft_strcmp(start->name, start->name) != 0 &&
			ft_strcmp(end->name, room->name) != 0)
			ft_printf("%s %d %d\n", room->name, room->x, room->y);
	ar_print(p->tubs, "%s\n");
}
