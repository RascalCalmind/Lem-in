/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 09:31:01 by lhageman      #+#    #+#                 */
/*   Updated: 2019/01/09 09:33:13 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	c1;
	unsigned char	c2;
	int				i;

	i = 0;
	while (s2[i] != '\0')
	{
		c1 = s1[i];
		c2 = s2[i];
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	if (s1[i] != '\0')
	{
		c1 = s1[i];
		c2 = s2[i];
		return (c1 - c2);
	}
	return (0);
}
