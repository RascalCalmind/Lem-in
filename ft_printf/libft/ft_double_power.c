/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_double_power.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 14:15:28 by mmarcell      #+#    #+#                 */
/*   Updated: 2019/07/21 15:18:23 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

double		ft_double_power(double base, int exp)
{
	double	result;

	result = 1;
	if (exp == 0)
		return (1);
	while (exp < 0)
	{
		result = result / base;
		++exp;
	}
	while (exp > 0)
	{
		result = result * base;
		--exp;
	}
	return (result);
}

long double	ft_ldouble_power(long double base, int exp)
{
	long double	result;

	result = 1;
	if (exp == 0)
		return (1);
	while (exp < 0)
	{
		result = result / base;
		++exp;
	}
	while (exp > 0)
	{
		result = result * base;
		--exp;
	}
	return (result);
}
