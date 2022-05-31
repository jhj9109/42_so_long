# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 20:39:37 by hyeonjan          #+#    #+#              #
#    Updated: 2022/05/31 20:41:07 by hyeonjan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L./minilibx_opengl_20191021/ -lmlx -framework OpenGL -framework AppKit

INC_LINK = -I ./includes

AR = ar rcus
RM = rm -f

SRC_DIR = ./srcs/
SRC2_DIR = ./bonus/

SRC_FILES = check_valid.c \
			exit.c \
			free.c \
			gnl.c \
			libft_obj.c \
			libft_utils.c \
			libft_utils2.c \
			map_init.c \
			map_render.c \
			move_trigger.c \
			object_render.c \
			object_response.c \
			on_frame.c \
			on_key_press.c \
			parse.c \
			so_long.c \
			t_args_init.c

SRC2_FILES = check_valid.c \
			exit.c \
			free.c \
			gnl.c \
			libft_obj.c \
			libft_utils.c \
			libft_utils2.c \
			map_init.c \
			map_render.c \
			move_trigger.c \
			object_render.c \
			object_response.c \
			on_frame.c \
			on_key_press.c \
			parse.c \
			so_long.c \
			t_args_init.c
			

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
SRCS2 = $(addprefix $(SRC2_DIR), $(SRC2_FILES))

SRC_OBJ = $(SRCS:.c=.o)
SRC2_OBJ = $(SRCS2:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(SRC2_OBJ)
else
	OBJ_FILES = $(SRC_OBJ)
endif

all: $(NAME)

bonus:
	@make WITH_BONUS=1 all	

%.o: %.c
	$(CC) $(CFLAGS) $(INC_LINK) -o $@ -c $<

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(INC_LINK) -o $(NAME) $(OBJ_FILES)

clean:
	$(RM) $(SRC_OBJ) $(SRC2_OBJ)

fclean: 
	make clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re
