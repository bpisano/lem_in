/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/16 12:49:24 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/21 13:09:20 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	link_names(char *str, char **n1, char **n2)
{
	int		i;

	i = -1;
	while (str[++i] != '-' && str[i])
		;
	*n1 = ft_strsub(str, 0, i);
	*n2 = ft_strsub(str, i + 1, ft_strlen(str) - i);
}

void	set_links(ft_array tubs, ft_array rooms)
{
	int		i;
	char	*n1;
	char	*n2;
	t_room	*r1;
	t_room	*r2;

	i = -1;
	while (tubs[++i])
	{
		link_names((char *)tubs[i], &n1, &n2);
		r1 = room_named(rooms, n1);
		r2 = room_named(rooms, n2);
		if (!r1 || !r2)
		{
			r1 ? free(n1) : 0;
			r2 ? free(n2) : 0;
			continue ;
		}
		ar_append(&(r1->link), (t_room *)r2);
		ar_append(&(r2->link), (t_room *)r1);
		free(n1);
		free(n2);
	}
}

void	set_rooms(t_data *d, ft_array rooms, ft_array *final_rooms)
{
	int		i;
	t_room	*room;

	if (ar_count(rooms) < 2)
		return ;
	i = -1;
	while (rooms[++i])
	{
		if (i > 0)
		{
			if (((char *)rooms[i - 1])[0] == '#')
			{
				room = new_room((char *)rooms[i]);
				ar_append(final_rooms, (t_room *)room);
				if (((char *)rooms[i - 1])[2] == 's')
					d->start = room;
				else
					d->end = room;
			}
			else
				ar_append(final_rooms, new_room((char *)rooms[i]));
		}
		else if (((char *)rooms[i])[0] != '#')
			ar_append(final_rooms, new_room((char *)rooms[i]));
	}
}

void	read_file(t_data *data, ft_array *rooms, ft_array *tubs)
{
	int		step;
	char	*line;

	step = 0;
	ar_init(rooms, 1);
	ar_init(tubs, 1);
	while (get_next_line(0, &line) > 0)
	{
		if (is_ants(line) && step == 0)
		{
			data->ants = ft_atoi(line);
			step = 1;
		}
		else if ((is_room(line) || is_command(line)) && step == 1)
			ar_append(rooms, (char *)line);
		else if (is_tub(line) && (step == 1 || step == 2))
		{
			ar_append(tubs, (char *)line);
			step = 2;
		}
		else if (!is_comment(line))
			break ;
	}
}

void	parse_data(t_data *d)
{
	int			i;
	ft_array	final_rooms;
	ft_array	rooms;
	ft_array	tubs;

	i = -1;
	ar_init(&final_rooms, 1);
	read_file(d, &rooms, &tubs);
	set_rooms(d, rooms, &final_rooms);
	set_links(tubs, final_rooms);

	/*
	i = -1;
	while (((d->start)->link)[++i])
	{
		printf("start linked to : %s\n", ((t_room *)((d->start)->link)[i])->name);
	}
	printf("start name : %s\n", (d->start)->name);*/
}
