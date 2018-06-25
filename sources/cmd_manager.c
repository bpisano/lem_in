/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmd_manager.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/08 18:34:01 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 19:53:36 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

/*
 ** Check if the line is a start command.
 ** Returns 1 if it is a start command. Else 0.
*/

int		is_start(char *str)
{
	return (ft_strcmp(str, "##start") == 0);
}

/*
 ** Check if the line is a end command.
 ** Returns 1 if it is a end command. Else 0.
*/

int		is_end(char *str)
{
	return (ft_strcmp(str, "##end") == 0);
}

/*
 ** Handle a room after a command to add it to the data.
*/

int		handle_cmd_room(char *line, t_parse *p)
{
	t_room	*new_room;

	if (is_room(line) && p->is_start == 1)
	{
		new_room = new_room_named(line);
		ar_append(&(p->rooms), new_room);
		p->start = new_room;
		p->is_start = -1;
	}
	else if (is_room(line) && p->is_end == 1)
	{
		new_room = new_room_named(line);
		ar_append(&(p->rooms), new_room);
		p->end = new_room;
		p->is_end = -1;
	}
	else
		return (0);
	return (1);
}

/*
 ** Set all the properties when encoutering a command.
*/

int		handle_cmd(char *line, t_parse *p)
{
	if (is_start(line) && p->is_start == 0 && p->is_end <= 0)
	{
		p->is_start = 1;
		free(line);
		return (1);
	}
	else if (is_end(line) && p->is_start <= 0 && p->is_end == 0)
	{
		p->is_end = 1;
		free(line);
		return (1);
	}
	return (0);
}
