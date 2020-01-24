/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hash.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 07:55:32 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/24 08:15:42 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_lem_in.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	char		*str;

	i = 0;
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while ((char)*s1)
	{
		str[i] = (char)*s1;
		i++;
		s1++;
	}
	while ((char)*s2)
	{
		str[i] = (char)*s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_atoi(const char *str)
{
	int i;
	int s;
	int	r;

	r = 0;
	i = 0;
	s = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (r * s);
}

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

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*cpy;

	len = 0;
	while (s1[len] != '\0')
	{
		len++;
	}
	cpy = (char *)malloc(sizeof(char) * (len) + 1);
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
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

unsigned int	ft_hash(unsigned int x, unsigned int y, unsigned int len)
{
	char			*str1;
	char			*str2;
	char			*new;
	unsigned int	num;

	str1 = ft_itoa(x);
	str2 = ft_itoa(y);
	new = ft_strjoin(str1, str2);
	num = ft_atoi(new);
	free(str1);
	free(str2);
	free(new);
	return (num % len);
}

int main(void)
{
	unsigned int i[20];
	unsigned int j;
	unsigned int ret;

	i[0] = 0;
	i[1] = 1;
	i[2] = 2;
	i[3] = 3;
	i[4] = 4;
	i[5] = 5;
	i[6] = 6;
	i[7] = 7;
	i[8] = 8;
	j = 0;
	while (j < 8)
	{
		ret = ft_hash(i[j], i[j + 1], 9);
		printf("[%i, %i] %i\n", j, j + 1, ret);
		j += 1;
	}
	return (0);
}
