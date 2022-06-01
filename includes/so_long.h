/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:34:52 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/01 12:47:44 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 32

# define TILE_IMAGE_LENGTH 4
# define PLAYER_IMAGE_LENGTH 9
# define COLLECTABLE_IMAGE_LENGTH 4
# define ENEMY_IMAGE_LENGTH 9

/*
	event mapping
*/
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_CLOSE 17

/*
	key mapping
*/
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# include "mlx.h"
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

/* enum */
typedef enum e_enum_obj
{
	OBJ_PLAYER,
	OBJ_COLLECTABLE,
	OBJ_ENEMY,
}			t_enum_obj;

typedef enum e_map
{
	MAP_EMPTY,
	MAP_WALL,
	MAP_EXIT,
	MAP_EXIT_OPEN,
}				t_map;

typedef enum e_directions
{
	UP,
	RIGHT,
	DOWN,
	LEFT
}				t_directions;

typedef enum e_status
{
	ERROR = -1,
	VALID,
}				t_status;

/* struct */

typedef struct s_object
{
	int				oid;
	int				type;
	int				r;
	int				c;
	int				status;
	int				img_num;
	int				move;
	struct s_object	*next;
}				t_object;

typedef struct s_args
{
	t_object	*obj;
	char		*lines;
	void		*tile_img[TILE_IMAGE_LENGTH];
	void		*player_img[PLAYER_IMAGE_LENGTH];
	void		*collectable_img[COLLECTABLE_IMAGE_LENGTH];
	void		*enemy_img[ENEMY_IMAGE_LENGTH];
	int			**map;
	int			w;
	int			h;
	int			collects;
	int			moved;
	void		*mlx;
	void		*win;
	int			finish;
}				t_args;

/* check_valid */
void		check_valid(t_args *x);

/* exit */
void		exit_error(t_args *x, char *s);
void		exit_invalid(t_args *x, char *s1, char *s2);
void		exit_valid(t_args *x);

/* free */
void		j_free(void *p);
void		free_args(t_args *x);

/* gnl */
char		*get_next_line(int fd);

/* libft_obj*/
t_object	*ft_objlast(t_object *head);
t_object	*ft_objnew(t_args *x, int type, int r, int c);
void		ft_obj_push_back(t_args *x, int type, int r, int c);

/* libft_utils */
char		*ft_strdup(char *buf);
char		*ft_strjoin(char *save, char *buf);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_calloc(size_t count, size_t size);
char		*ft_itoa(char *p, int n);

/* libft_utils2 */
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize);
char		*ft_strchr(const char *str, int c);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strjoin_or_dup(char *prev, char *added);

/* map_init */
void		map_init(t_args *x);

/* map_render */
void		map_render(t_args *x);

/* object_render */
void		object_render(t_args *x);

/* object_response */
void		object_response(t_args *x, int r, int c);

/* can_move */
void		move_trigger(t_args *x, t_object *player, int direction);

/* on_frame */
int			on_frame(t_args *x);

/* on_key_press */
int			on_key_press(int keycode, t_args *x);

/* parse */
void		parse(t_args *x, char *file_name);

/* t_args_init */
void		t_args_init(t_args **x);

#endif
