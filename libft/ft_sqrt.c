/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sqrt.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 19:23:52 by lhageman      #+#    #+#                 */
/*   Updated: 2020/02/12 19:33:53 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(double n)
{
	double i;

	i = 0.01;
	while ((i * i) < n)
	{
		i += 0.01;
	}
	if (i >= 0.01)
		return (i - 0.01);
	return (i);
}
