/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_paths.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: Lotte <Lotte@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/28 20:05:48 by Lotte         #+#    #+#                 */
/*   Updated: 2020/05/15 15:29:52 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static void	ft_free_ants(t_path *path)
{
	int i;

	i = 0;
	if (path->ants != NULL)
	{
		while (path->ants[i] != NULL && i < path->ants_len)
		{
			if (path->ants[i])
			{
				free(path->ants[i]);
				path->ants[i] = NULL;
			}
			i += 1;
		}
		free(path->ants);
		path->ants = NULL;
	}
}

int			ft_free_paths(t_lemin *lem)
{
	unsigned int i;

	i = 0;
	if (lem->paths != NULL)
	{
		while (i < lem->rooms)
		{
			if (lem->paths[i]->room)
			{
				free(lem->paths[i]->room);
				lem->paths[i]->room = NULL;
			}
			if (lem->paths[i]->ants)
			{
				ft_free_ants(lem->paths[i]);
			}
			free(lem->paths[i]);
			lem->paths[i] = NULL;
			i += 1;
		}
		free(lem->paths);
		lem->paths = NULL;
	}
	return (1);
}
