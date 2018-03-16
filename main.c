/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 18:37:54 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 14:14:19 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem-in.h"

int		main(void)
{
	t_data		data;

	parse_data(&data);
	eval(data.end, data.start,0);
	resolve(&data);
}

void	eval(t_data *room, t_data *finish, int k)
{
	int		i;

	i = -1;
	if (k > room->score)
		return ;
	room.score = k;
	if (finish == room)
		return ;
	while (room->link[++i])
			eval(room->link[i], k + 1);
}

void	resolve(t_data *data)
{

}
