/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/08 14:33:26 by lhageman       #+#    #+#                */
/*   Updated: 2020/02/08 14:46:05 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lem_in.h"

void	ft_swap_room(t_room **open, int a, int b)
{
	t_room *temp;

	temp = open[a];
	open[a] = open[b];
	open[b] = temp;
}

int		ft_quicksort(t_room **open, int low, int high)
{
	int		pivot;
	int		i;
	int		j;

	if (!open)
		return (-1);
	if (low < high)
	{
		pivot = low;
		i = low;
		j = high;
		while (i < j)
		{
			while ((open[i]->f <= open[pivot]->f) && (i < high))
				i += 1;
			while (open[i]->f > open[pivot]->f)
				j -= 1;
			if (i < j)
				ft_swap_room(open, i, j);
		}
		ft_swap_room(open, pivot, j);
		ft_quicksort(open, low, j - 1);
		ft_quicksort(open, j + 1, high);
	}
	return (0);
}
