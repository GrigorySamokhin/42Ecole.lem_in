# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 18:55:18 by gmeizo            #+#    #+#              #
#    Updated: 2019/04/16 13:08:42 by gmeizo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEM_IN			= lem-in
LEM_INV			= lem-in-visu

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra

_SRCS			=	list_func.c \
						parse_func.c \
						bfs_func.c \
						bfs_func_two.c \
						bfs_func_three.c \
						levels_func.c \
						queue_bfs_func.c \
						path_list_func.c \
						path_shortcut.c \
						path_shortcut_two.c \
						path_shortcut_three.c \
						ant_func.c \
						final_func.c \
						final_func_two.c \
						parse_func_two.c \
						parse_func_three.c \
						create_lists.c \
						clear_func.c \
						ant_func_two.c \
						ant_func_add.c \
						ant_func_three.c \
						parse_func_two_d.c \

_L_SRCS			=	lem_in.c
_L_SRCS			+=	$(_SRCS)
_V_SRCS			=		lem_in_visu.c \
						control_keys.c \
						free_one.c \
						lst_func.c \
						add_func.c \
						map_n_cord.c \
						print_lines.c \
						print_links.c \

_V_SRCS			+=	$(_SRCS)

_MLX			=	libmlx.a
_LIBFT			=	libft.a
HEADER_DIR		=	includes
HEADER			=	$(HEADER_DIR)/lem_in.h

SRCS_DIR		= source
LIB_DIR			= libft
MLX_DIR			= minilibx
L_SRCS			= $(addprefix $(SRCS_DIR)/, $(_L_SRCS))
V_SRCS			= $(addprefix $(SRCS_DIR)/, $(_V_SRCS))
MLX				= $(addprefix $(MLX_DIR)/, $(_MLX))
LIBFT			= $(addprefix $(LIB_DIR)/, $(_LIBFT))
L_OBJS			= $(L_SRCS:.c=.o)
V_OBJS			= $(V_SRCS:.c=.o)

_GREEN=\x1b[32m
_END=\x1b[0m

all: $(LEM_IN) $(LEM_INV)

$(LEM_IN): $(HEADER) $(LIBFT) $(L_OBJS)
		@$(CC) $(CFLAGS) -o $(LEM_IN) $(L_OBJS) -L$(LIB_DIR) -lft -I $(HEADER_DIR)
		@echo "$(LEM_IN) : $(_GREEN)Done$(_END)"

$(LEM_INV): $(HEADER) $(LIBFT) $(MLX) $(V_OBJS)
		@$(CC) $(CFLAGS) -o $(LEM_INV) $(V_OBJS) -I /usr/local/include -L minilibx/ -lmlx -framework OpenGL -framework AppKit -L$(LIB_DIR) -lft -I $(HEADER_DIR)
		@echo "$(LEM_INV) : $(_GREEN)Done$(_END)"

$(MLX):
		@make -C $(MLX_DIR)

$(LIBFT):
		@make -C $(LIB_DIR)

%.o : %.c
		@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DIR)

clean:
		@make fclean -C $(LIB_DIR)
		@make clean -C $(MLX_DIR)
		@/bin/rm -f $(L_OBJS) $(V_OBJS)
		@echo "$(LEM_IN) clean : $(_GREEN)Done$(_END)"
		@echo "$(LEM_INV) clean : $(_GREEN)Done$(_END)"

fclean: clean
		@/bin/rm -f $(LEM_IN) $(LEM_INV)
		@echo "$(LEM_IN) fclean : $(_GREEN)Done$(_END)"
		@echo "$(LEM_INV) fclean : $(_GREEN)Done$(_END)"

re:
		@make fclean
		@make

.PHONY: all clean fclean re

