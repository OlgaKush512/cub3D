# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 11:12:25 by cbeaurai          #+#    #+#              #
#    Updated: 2022/02/07 17:29:49 by cbeaurai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

SRCS		=	main.c parsing/check_arg.c parsing/check_input.c parsing/exit_utils.c \
				parsing/store_data.c parsing/parse_map.c parsing/parse_value.c \
				parsing/check_data.c parsing/print_data.c parsing/check_data_utils.c \
				raycasting/actions.c raycasting/draw_3dray.c  \
				raycasting/get_color.c raycasting/init_1.c parsing/parsing_utils.c \
				raycasting/map.c raycasting/std_fonctions.c parsing/check_input_utils.c\
				raycasting/check_horizon.c raycasting/check_vertical.c raycasting/prepa_raycasting.c\
				raycasting/draw_player_line.c raycasting/destroy_and_free.c raycasting/init_map.c\
				raycasting/input_keys.c raycasting/input_func.c \
				#map_init_and_check/check_map map_init_and_check/check_wall_attributs.c \
				#map_init_and_check/clear_map_list.c map_init_and_check/fonctions_list.c \
				#smap_init_and_check/read_map.c raycasting/drow_tile.c \

OBJS		= $(SRCS:.c=.o)

CC			= gcc

RM			= rm -rf

LFT			= ./libft

CFLAGS		= -Wall -Werror -Wextra -no-pie -g -I.

LIBS		= -L ./libft -lft -L ./mlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lbsd

MAKE_LIB	= ${MAKE} -C ${LFT}

all:		$(NAME)

.c .o	:
			${CC} ${CFLAGS} -I ./inc -I ./mlx_linux -c $< -o $(<:.c=.o)
			
$(NAME):	$(OBJS)
			$(MAKE_LIB) && make -C ./mlx_linux
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean:		
			$(RM) $(OBJS)
			$(MAKE_LIB) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE_LIB) fclean

re:			fclean $(NAME)

.PHONY:		all clean fclean re
