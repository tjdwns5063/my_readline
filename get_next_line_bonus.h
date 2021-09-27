/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:03:21 by seongjki          #+#    #+#             */
/*   Updated: 2021/05/25 14:01:38 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	int				fd;
	char			*str;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(char const *str);
char				*ft_strjoin(char *s1, char *s2);
t_list				*ft_lstnew(int fd);
t_list				*ft_lstfind(t_list **lst, int fd);
int					make_line(char **str, char **line);
int					str_in_newline(char *str);
char				*ft_strdup(char *s1);
int					get_next_line(int fd, char **line);
void				ft_lstclear(t_list **lst, t_list *target);
int					decide_ret(int ret, char **line,
					t_list **lst, t_list *target);

#endif
