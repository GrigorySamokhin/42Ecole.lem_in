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

NAME			= libft.a

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra

_LIBS			=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
					ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
					ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
					ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
					ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
					ft_atoi.c ft_itoa.c ft_itoa_base.c ft_isalpha.c \
					ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
					ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
					ft_strnew.c ft_strdel.c ft_strclr.c ft_putstr.c \
					ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
					ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
					ft_strtrim.c ft_strsplit.c ft_putchar.c ft_putstr.c \
					ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
					ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
					ft_isspace.c ft_strchrindex.c ft_charinset.c \
					ft_strjoinclr.c ft_count_chr.c ft_isnan.c ft_numbsize.c\
					ft_strsplit_char.c \

_GNLS			=	get_next_line.c 

_PRINTFS		=	printf_add.c \
					ft_printf.c \
					printf_di.c \
					print_b.c \
					print_g.c \
					printf_e.c \
					printf_f.c \
					printf_ftwo.c \
					printf_ou.c \
					printf_s.c \
					printf_set_v.c \
					printf_set.c \
					printf_xchp.c \

LIBS_DIR		= main_functions
GNLS_DIR		= get_next_line
PRINTFS_DIR		= ft_printf
LIBS			= $(addprefix $(LIBS_DIR)/, $(_LIBS))
GNLS			= $(addprefix $(GNLS_DIR)/, $(_GNLS))
PRINTFS			= $(addprefix $(PRINTFS_DIR)/, $(_PRINTFS))
OBJS			= $(LIBS:.c=.o)
G_OBJS			= $(GNLS:.c=.o)
P_OBJS			= $(PRINTFS:.c=.o)
OBJS			+= $(G_OBJS)
OBJS			+= $(P_OBJS)

#COLORS
_CYAN=\x1b[36m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_END=\x1b[0m

all: $(NAME)

$(NAME): $(OBJS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "$(NAME) : $(_GREEN)Done$(_END)"

%.o : %.c
		@$(CC) $(CFLAGS) -c $< -o $@ -I includes/

clean:
		@/bin/rm -f $(OBJS)
		@echo "libft clean : $(_GREEN)Done$(_END)"

fclean: clean
		@/bin/rm -f $(NAME)
		@echo "libft fclean : $(_GREEN)Done$(_END)"

re:
		@make fclean
		@make

.PHONY: all clean fclean re