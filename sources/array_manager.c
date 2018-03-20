/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   array_manager.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 19:21:03 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 14:32:28 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int		ar_init(ft_array *array, size_t size)
{
	int		i;

	if (!(*array = (ft_array)malloc(sizeof(void *) * (size + 1))))
		return (0);
	i = 0;
	while (i < (int)size)
		(*array)[i++] = NULL;
	return (1);
}

int		ar_count(ft_array array)
{
	int		i;

	i = -1;
	while (array[++i])
		;
	return (i);
}

int		ar_append(ft_array *array, void *value)
{
	ft_array	new;
	int			count;
	int			i;

	count = ar_count(*array);
	MALLRET(ar_init(&new, count + 1));
	i = -1;
	while (++i < count)
		new[i] = (*array)[i];
	new[i] = value;
	new[i + 1] = NULL;
	free(*array);
	*array = new;
	return (1);
}
