/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/16 12:49:24 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 16:40:16 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

/*
 ** Init all the parsing data.
*/

static void	init_parse_data(t_parse *p)
{
	ar_init(&(p->rooms), 1);
	ar_init(&(p->tubs), 1);
	p->is_start = 0;
	p->is_end = 0;
	p->ants = 0;
	p->start = NULL;
	p->end = NULL;
}

/*
 ** Assign the number of ants to the parsing data.
*/

static int	get_ants(t_parse *p)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "") == 0)
		{
			free(line);
			return (0);
		}
		if (is_ants(line))
		{
			p->ants = ft_atoi(line);
			free(line);
			return (1);
		}
		else if (is_comment(line))
			free(line);
		else
		{
			free(line);
			return (0);
		}
	}
	return (1);
}

/*
 ** Returns all the data of a file in a t_array.
*/

static int	get_data(t_parse *p)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "") == 0)
		{
			free(line);
			return (1);
		}
		if (handle_cmd(line, p) || handle_cmd_room(line, p))
			;
		else if (is_room(line))
			ar_append(&(p->rooms), new_room_named(line));
		else if (is_tub(line))
			ar_append(&(p->tubs), line);
		else if (is_comment(line))
			free(line);
		else
		{
			free(line);
			return (0);
		}
	}
	return (1);
}

/*
 ** Parse the data from the 0 fd.
 ** Returns 1 if the parsing is correct. Else 0.
*/

int			parse(t_data *d)
{
	t_parse	parse_data;

	init_parse_data(&parse_data);
	if (!get_ants(&parse_data))
	{
		handle_error(&parse_data);
		return (0);
	}
	if (!get_data(&parse_data))
	{
		handle_error(&parse_data);
		return (0);
	}
	if (!parse_data.start || !parse_data.end || !link_rooms(&parse_data))
	{
		handle_error(&parse_data);
		return (0);
	}
	d->start = parse_data.start;
	d->end = parse_data.end;
	d->room_nbr = ar_count(parse_data.rooms);
	d->ants = parse_data.ants;
	d->rooms = parse_data.rooms;
	print_parse(&parse_data);
	free_parse(&parse_data);
	return (1);
}
