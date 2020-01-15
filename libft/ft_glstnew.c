/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 09:27:37 by lhageman      #+#    #+#                 */
/*   Updated: 2019/01/25 09:27:44 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_glist	*ft_glstnew(void const *content, size_t content_size)
{
	t_glist	*list;

	list = (t_glist *)malloc(sizeof(t_glist));
	if (list == NULL)
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = ft_memalloc(content_size);
		if (list->content == NULL)
		{
			free(list);
			return (NULL);
		}
		ft_memcpy((list->content), content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
