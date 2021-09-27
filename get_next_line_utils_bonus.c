/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:32:23 by seongjki          #+#    #+#             */
/*   Updated: 2021/05/25 13:46:37 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char const *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		str_in_newline(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	len;
	size_t	idx;

	idx = 0;
	if (!s1)
	{
		ret = ft_strdup(s2);
		return (ret);
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	while (*(s1 + idx))
	{
		*(ret + idx) = *(s1 + idx);
		idx++;
	}
	free(s1);
	while (*s2)
		*(ret + idx++) = *s2++;
	*(ret + idx) = '\0';
	return (ret);
}

t_list	*ft_lstnew(int fd)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->fd = fd;
	lst->str = 0;
	lst->next = 0;
	return (lst);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
