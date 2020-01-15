/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 16:28:49 by lhageman      #+#    #+#                 */
/*   Updated: 2019/01/21 16:28:51 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		posit(int *n, int *posneg)
{
	if (*n < 0)
	{
		*n = *n * -1;
		*posneg = 1;
	}
}

static void		inlen(int *intlen, int *temp)
{
	while (*temp >= 10)
	{
		*temp = *temp / 10;
		*intlen = *intlen + 1;
	}
}

char			*ft_itoa(int n)
{
	int		temp;
	int		intlen;
	char	*str;
	int		posneg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	intlen = 2;
	posneg = 0;
	if (n < 0)
		posit(&n, &posneg);
	temp = n;
	inlen(&intlen, &temp);
	intlen = intlen + posneg;
	if ((str = (char *)malloc(sizeof(char) * intlen)) == NULL)
		return (NULL);
	str[--intlen] = '\0';
	while (intlen--)
	{
		str[intlen] = n % 10 + '0';
		n = n / 10;
	}
	if (posneg > 0)
		str[0] = '-';
	return (str);
}
