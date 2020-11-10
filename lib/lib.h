/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 12:05:34 by wupdegra          #+#    #+#             */
/*   Updated: 2020/08/28 10:49:05 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

/*
**	Lib
*/

char			*ft_strchr(const char *str, int ch);
char			*ft_strrchr(const char *str, int ch);
size_t			ft_strlen(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_memcpy(void *dest, const void *src, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
bool			ft_isdigit(int ch);
bool			ft_isnumeric(const char *str);
int				ft_atoi(const char *str);
char			**ft_split(char const *s, char c);
void			*ft_calloc(size_t num, size_t size);
void			*ft_memset(void *ptr, int ch, size_t len);

/*
**	List
*/

typedef	struct	s_list
{
	struct s_list	*next;
	void			*content;
}				t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));

/*
** Gnl
*/

# define BUFFER_SIZE 1

int				get_next_line(int fd, char **line);

typedef struct	s_list_gnl
{
	int					fd;
	char				*rem;
	struct s_list_gnl	*next;
}				t_list_gnl;

t_list_gnl		*ft_lstnew_gnl(int fd);
void			ft_lstremove_gnl(t_list_gnl **lst, int fd);

#endif
