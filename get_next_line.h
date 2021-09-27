/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:36:27 by seongjki          #+#    #+#             */
/*   Updated: 2021/05/25 15:47:23 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
int					make_line(char **str, char **line);
int					str_in_newline(char *str);
char				*ft_strdup(char *s1);
int					get_next_line(int fd, char **line);
int					decide_ret(int ret, char **str, char **line);

#endif
