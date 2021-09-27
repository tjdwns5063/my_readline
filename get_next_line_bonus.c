/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:04:49 by seongjki          #+#    #+#             */
/*   Updated: 2021/05/25 14:04:57 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_lstfind(t_list **lst, int fd)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	new = ft_lstnew(fd);
	new->next = *lst;
	*lst = new;
	return (new);
}

void	ft_clear(t_list **lst, t_list *target)
{
	t_list	*current;

	current = *lst;
	if (current->fd == target->fd)
	{
		*lst = current->next;
		free(target->str);
		free(target);
		return ;
	}
	while (current->next->fd != target->fd)
		current = current->next;
	current->next = target->next;
	free(target->str);
	free(target);
	return ;
}

int		make_line(char **str, char **line)
{
	char	*tmp;
	int		n_idx;

	n_idx = str_in_newline(*str);
	(*str)[n_idx] = '\0';
	*line = ft_strdup(*str);
	tmp = ft_strdup((*str) + (n_idx + 1));
	free(*str);
	*str = tmp;
	return (1);
}

int		decide_ret(int ret, char **line, t_list **lst, t_list *target)
{
	if (ret == -1)
	{
		ft_clear(lst, target);
		return (-1);
	}
	else if (target->str && str_in_newline(target->str) >= 0)
	{
		make_line(&target->str, line);
		return (1);
	}
	else if (target->str)
	{
		*line = ft_strdup(target->str);
		ft_clear(lst, target);
		return (0);
	}
	*line = ft_strdup("");
	ft_clear(lst, target);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*lst;
	t_list			*target;
	int				ret;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	target = ft_lstfind(&lst, fd);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer || !target)
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		target->str = ft_strjoin(target->str, buffer);
		if (str_in_newline(target->str) >= 0)
		{
			free(buffer);
			return (make_line(&target->str, line));
		}
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (decide_ret(ret, line, &lst, target));
}
