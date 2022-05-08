/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:34:52 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/06 19:34:53 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>//perror, strerror
# include <fcntl.h>//open, close, read, write
# include <stdlib.h>//malloc, free, exit

typedef struct s_list {
	char			*line;
	struct s_list	*next;
}				t_list;

typedef struct s_player {
	int	r;
	int c;
	int collect;
}				t_player;

typedef struct s_args {
	t_list		*head;
	t_player	*p;
	int			**map;
	int			c;
	int			w;
	int			h;
}				t_args;

typedef enum e_map
{
	EMPTY,
	WALL,
	COLLECTABLE,
	MAP_EXIT,
	PLAYER,
}				t_map;

/* gnl */
char	*get_next_line(int fd);

/* libft_utils */
char	*ft_strdup(char *buf);
char	*ft_strjoin(char *save, char *buf);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

/* libft_utils2 */
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
char	*ft_strchr(const char *str, int c);
void	ft_putstr_fd(char *s, int fd);

/* libft_lst */
t_list	*ft_lstnew(char	*line);
t_list	*ft_lstlast(t_list *head);
void	ft_lstiter(t_list *head, void (*f)(char *));
void	ft_lstclear(t_list **head);
void	ft_lst_delone(t_list **head, t_list *deleted);

/* check_valid */
bool	check_valid(t_args *x, char *lines);

/* exit */
void	exit_error(t_args *x, char *s);
void	exit_invalid(t_args *x, char *s1, char *s2);
void	exit_valid(t_args *x);

#endif
