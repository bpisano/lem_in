/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem-in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 18:44:38 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 13:35:25 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM-IN_H
# define LEM-IN_H

# include "libft.h"

# define MALLCHECK(x) if (!x) return (-1);

typedef struct	s_room
{
	char		*name;
	int			x;
	int			y;
	int			score;
	t_room		**link;
}				t_room;

typedef struct	s_data
{
	t_room		*start;
	t_room		*end;
	int			room_nbr;
	int			ants;
}				t_data;

#endif
