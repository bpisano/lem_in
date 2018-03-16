/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem-in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 18:44:38 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 19:36:24 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM-IN_H
# define LEM-IN_H

# include "libft.h"

typedef struct	s_start
{
	char		*name;
	int			x;
	int			y;
	t_sal		**link;
}				t_start;

typedef struct	s_end
{
	char		*name;
	int			x;
	int			y;
	t_sal		**link;
}				t_end;

typedef struct	s_sal
{
	char		*name;
	int			x;
	int			y;
	t_sal		**next;
	t_sal		**link;
}				t_sal;

typedef struct	s_lem
{
	t_start		*start;
	t_end		*end;
	char		command;
	int			ants;
	t_sal		*lst;
}				t_lem;

#endif
