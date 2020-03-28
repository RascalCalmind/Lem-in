/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_paths.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: Lotte <Lotte@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/28 20:05:48 by Lotte          #+#    #+#                */
/*   Updated: 2020/03/28 20:07:08 by Lotte         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void		ft_free_ants(t_path *path)
{
	int i;

	i = 0;
	if (path->ants != NULL)
	{
		while (path->ants[i] != NULL)
		{
			free(path->ants[i]);
			path->ants[i] = NULL;
			i += 1;
		}
		free(path->ants);
		path->ants = NULL;
	}
}

int			ft_free_paths(t_lemin *lem)
{
	int i;


	i = 0;
	if (lem->paths)
	{
		while(lem->paths[i])
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
		free (lem->paths);
		lem->paths = NULL;
	}
	return (0);
}