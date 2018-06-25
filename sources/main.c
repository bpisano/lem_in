/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 21:19:38 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 16:56:01 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	print_result(t_data *data)
{
	int		tab[2];
	int		z;

	tab[1] = -1;
	while (++tab[1] < data->nb_turnmax && (tab[0] = -1))
	{
		z = 0;
		while (data->pos[++tab[0]])
			if (((t_room *)(data->pos[tab[0]]))->ants[tab[1]])
			{
				if (z)
					ft_printf(" ");
				z = ft_printf("L%d-%s", ((t_room *)(data->pos[tab[0]]))->
				ants[tab[1]], ((t_room *)(data->pos[tab[0]]))->name);
			}
		tab[0] = -1;
		while (data->ends[tab[1]][++tab[0]])
		{
			if (z || tab[0])
				ft_printf(" ");
			ft_printf("L%d-%s", data->ends[tab[1]][tab[0]], data->end->name);
		}
		if (tab[0] || z)
			ft_printf("\n");
	}
}

int		tittake(t_room *room, int turn, t_data *data)
{
	int		i;
	int		j;

	if (room == data->end)
		return (turn);
	if (turn >= room->turn && turn != 0)
		return (SCORE_MAX);
	room->turn = turn;
	if (!(room->ants))
		if (!(room->ants = ft_memalloc(sizeof(int) * (data->nb_turnmax))))
			return (0);
	while (room->ants[turn])
		turn++;
	i = -1;
	while (room->link[++i])
	{
		j = tittake((t_room *)(room->link[i]), turn + 1, data);
		if (j != SCORE_MAX)
		{
			((t_room *)(room->link[i]))->c_score = j;
			if (((t_room *)(room->link[i]))->c_score < room->c_score)
				room->c_score = ((t_room *)(room->link[i]))->c_score;
		}
	}
	return (room->c_score);
}

int		fill_ant(t_room *room, int turn, t_data *data, int score)
{
	int		tab[2];

	if ((tab[0] = -1) && room == data->end)
	{
		while (data->ends[turn][++tab[0]])
			;
		return (data->ends[turn][tab[0]] = data->ant);
	}
	if (turn > room->turn)
		return (0);
	while (room->ants[turn])
		turn++;
	while (room->link[++tab[0]] && !(tab[1] = 0))
		if ((score == ((t_room *)(room->link[tab[0]]))->c_score
		|| ((t_room *)(room->link[tab[0]])) == data->end) &&
		fill_ant(((t_room *)(room->link[tab[0]])), turn + 1, data, score))
		{
			if (room != data->start)
				room->ants[turn] = data->ant;
			while (data->pos[tab[1]] != room && data->pos[tab[1]] != 0)
				tab[1]++;
			data->pos[tab[1]] = room;
			return (1);
		}
	return (0);
}

void	resolve(t_data *data)
{
	int		j;

	data->ant = 0;
	while (++(data->ant) <= data->ants)
	{
		if (!(fill_ant(data->start, 0, data, tittake(data->start, 0, data))))
		{
			ft_printf("ERRORwdjhkjdh\n");
			return ;
		}
		j = -1;
		while (((t_room *)(data->rooms[++j])))
		{
			((t_room *)(data->rooms[j]))->c_score = SCORE_MAX;
			((t_room *)(data->rooms[j]))->turn = SCORE_MAX;
		}
		data->start->c_score = SCORE_MAX;
	}
	print_result(data);
}

int		main(void)
{
	t_data		data;
	int			i;

	i = -1;
	if (!parse(&data))
		return (0);
	if (!(data.pos = ft_memalloc(sizeof(void *) * (data.room_nbr))))
		return (0);
	data.nb_turnmax = data.ants + data.room_nbr - 1;
	if (!(data.ends = ft_memalloc(sizeof(int *) * (data.nb_turnmax))))
		return (0);
	while (++i < data.nb_turnmax)
		if (!(data.ends[i] = ft_memalloc(sizeof(int) * (data.ants + 1))))
			return (0);
	resolve(&data);
	free_data(&data);
	return (0);
}
