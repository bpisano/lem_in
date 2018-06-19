/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 21:19:38 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/15 15:11:16 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int		tittake(t_room *room, int turn, t_data *data)
{
	int		i;
	int		j;

//	printf("nom de la salle actuelle : %s turn : %d\n",room->name, turn);
	if (room == data->end)
	{
//		printf("  %s : %d\n", room->name, turn);
		return (turn);
	}
	if (turn > room->turn)
	{
//		printf("  room par laquelle on est deja passer %s car room->turn :%d et que turn :%d\n", room->name, room->turn, turn);
		return (SCORE_MAX);
	}
	room->turn = turn;
	if (!(room->ants))  
	{
		if (!(room->ants = ft_memalloc(sizeof(int) * (data->nb_turnmax))))
			return (0);
	}
	else
	{
		while (room->ants[turn])
		{
//			printf("wait a turn\n");
			turn++;
		}
	}
	i = -1;
	while (room->link[++i])
	{
		j = tittake((t_room *)(room->link[i]), turn + 1, data);
		if (j != SCORE_MAX)
		{
			((t_room *)(room->link[i]))->c_score = j;
	//		printf("fin recursive %s : %d\nalors que room->c_score : %d\n",((t_room *)(room->link[i]))->name, ((t_room *)(room->link[i]))->c_score, room->c_score);
			if (((t_room *)(room->link[i]))->c_score < room->c_score)
			{
	//			printf("changement de score de la salle %s : %d pour %d\n",room->name, room->c_score, ((t_room *)(room->link[i]))->c_score);
				room->c_score = ((t_room *)(room->link[i]))->c_score;
	//			printf("nouveau score :%d\n", room->c_score);
			}
		}
	}
//	printf("%s retourne %d\n",room->name, room->c_score);
	return (room->c_score);
}

void	fill_ant(int score, t_room *room, t_data *data, int ant)
{
	int		i;
	int		j;
	int		turn;

	turn  = 0;
	printf("\n%d\n", score);
	while (ft_strcmp(room->name, "1"))
	{
		i = 0;
		j = 0;
		while (((t_room *)(room->link[i]))->c_score != score)
			i++;
		while (data->pos[j] != (room->link[i]) && data->pos[j] != 0)
			j++;
		data->pos[j] = room->link[i];
		while (room->ants[turn])
		{
//			printf("wait a turn\n");
			turn++;
		}
		if (room != data->start)
		{
//			printf("remplissage %s : %d\n", room->name, turn);
			room->ants[turn] = ant;
		}
//		printf("nom %s turn %d :%d\n", room->name, turn,room->ants[turn]);
		room->turn = SCORE_MAX;
		room->c_score = SCORE_MAX;
		room = room->link[i];
		turn++;
//		printf("next turn\n");
	}
}

void	resolve(t_data *data)
{
	int		i;

	i = 0;
	while (++i <= data->ants)
	{
		fill_ant(tittake(data->start, 0, data), data->start, data, i);
	}
}

int		main(void)
{
	t_data      data;

	if (!(data.pos = ft_memalloc(sizeof(void *) * (data.room_nbr))))
		return (0);
	parse(&data);
	data.nb_turnmax = data.ants + data.room_nbr - 1;
	resolve(&data);
//	printf("%s", ((t_room *)(data.start->link[1]))->name);
	return (0);
}