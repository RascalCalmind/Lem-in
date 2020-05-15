/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_power.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 16:04:32 by wmisiedj      #+#    #+#                 */
/*   Updated: 2019/07/20 10:25:18 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long long		ft_power(int base, unsigned int exp)
{
	long long result;

	result = 1;
	if (exp == 0)
		return (1);
	while (exp > 0)
	{
		result = result * base;
		exp--;
	}
	return (result);
}
