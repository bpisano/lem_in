/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/16 12:49:24 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 17:35:37 by bpisano     ###    #+. /#+    ###.fr     */
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

	if (!get_next_line(0, &line))
		return (0);
	if (!is_ants(line))
		return (0);
	p->ants = ft_atoi(line);
	return (1);
}

static int	handle_cmd(char *line, t_parse *p)
{
	if (is_room(line) && p->is_start == 1)
	{
		ar_append(&(p->rooms), new_room_named(line));
		p->start = new_room_named(line);
		p->is_start = -1;
	}
	else if (is_room(line) && p->is_end == 1)
	{
		ar_append(&(p->rooms), new_room_named(line));
		p->end = new_room_named(line);
		p->is_end = -1;
	}
	else
		return (0);
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
			return (1);	
		if (is_start(line) && p->is_start == 0 && p->is_end <= 0)
			p->is_start = 1;
		else if (is_end(line) && p->is_start <= 0 && p->is_end == 0)
			p->is_end = 1;
		else if (handle_cmd(line, p))
			;
		else if (is_room(line))
			ar_append(&(p->rooms), new_room_named(line));
		else if (is_tub(line))
			ar_append(&(p->tubs), line);
		else if (is_comment(line))
			continue ;
		else
			return (0);
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
	if (!get_ants(&parse_data) || !get_data(&parse_data))
	{
		printf("0\n");
		handle_error(&parse_data);
		return (0);
	}
	if (!parse_data.start || !parse_data.end)
	{
		printf("1\n");
		handle_error(&parse_data);
		return (0);
	}
	if (!link_rooms(&parse_data))
	{
		printf("2\n");
		handle_error(&parse_data);
		return (0);
	}
	d->start = parse_data.start;
	d->end = parse_data.end;
	d->room_nbr = ar_count(parse_data.rooms);
	d->ants = parse_data.ants;

	// Print result
	printf("start : %s\n", d->start->name);
	printf("end : %s\n", d->end->name);
	int i = -1;
	while (parse_data.rooms[++i])
	{
		t_room *r = (t_room *)parse_data.rooms[i];
		printf("room : %s\n", r->name);
		int j = -1;
		while (r->link[++j])
		{
			printf("\tlinked to : %s\n", ((t_room *)r->link[j])->name);
		}
	}
	return (1);
}
