/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "mlx.h"
# include <math.h>

typedef struct			s_draw
{
	int					delta_x;
	int					delta_y;
	int					sign_x;
	int					sign_y;
	int					error;
	int					error2;
}						t_draw;

typedef struct			s_dot
{
	int					x;
	int					y;
}						t_dot;

typedef struct			s_room
{
	const char			*name;
	int					x;
	int					y;
	int					b;
	int					boo;
	t_list				*pipes;
}						t_room;

typedef struct			s_bres
{
	int					dx;
	int					dy;
	float				m;
	int					adjust;
	float				offset;
	float				threshold;
	float				delta;
	int					x;
	int					y;
	int					x1;
	int					x2;
	int					y1;
	int					y2;
}						t_bres;

typedef struct			s_queue
{
	struct s_adjlst		*link;
	struct s_queue		*next_queue;
}						t_queue;

typedef struct			s_lst
{
	struct s_adjlst		*link;
	struct s_lst		*next_links;
}						t_links;

typedef struct			s_way
{
	struct s_adjlst		*node;
	struct s_way		*next_way;
}						t_way;

typedef	struct			s_paths
{
	struct s_way		*link;
	struct s_paths		*next_paths;
}						t_paths;

typedef struct			s_adjlst
{
	char				*name;
	int					x;
	int					y;
	int					intersection;
	int					path;
	int					test_path;
	int					ant;
	int					ret;
	int					count;
	int					start;
	int					end;
	int					shortcut;
	int					engaged;
	int					pos;
	int					visited;
	int					vis_fin;
	int					link;
	int					cor_x;
	int					cor_y;
	t_links				*links;
	struct s_adjlst		*next_adj;
}						t_adjlst;

typedef struct			s_info
{
	int					ways;
	int					count;
	int					numb_ant;
	int					ways_all;
	int					pos;
	int					numb;
	int					inter;
	int					fd;
	int					ret;
	int					max_pos;
	long				sum_ants;
	int					sum_queue;
	int					sum_rooms;
	int					to_count;
	t_adjlst			*end;
	t_adjlst			*start;
}						t_info;

typedef struct			s_visu
{
	int					**coords;
	t_list				*t;
	t_list				*room_state;
	t_adjlst			*adjlst;
	t_info				*info;
	int					step;
	int					win_x;
	int					win_y;
	int					b_x;
	int					b_y;
	int					s_x;
	int					s_y;
	int					x;
	int					y;
	int					scale;
	void				*mlx_ptr;
	void				*win_ptr;
}						t_visu;

int						i_free(t_info *info);
int						array_len(t_paths *paths_all, t_info *info);
void					ft_char_two_dem(char **array);
void					bresenham(t_visu *visu, t_dot *d1, t_dot *d2);
void					draw_square(t_visu *visu, int x, int y, int color);
int						i_free(t_info *info);
void					ft_swap(int *a, int *b);
void					ft_free2(void **tab);
char					**get_words(char **tab);
void					ft_char2dump(char **array);
t_list					*ft_lstcreate(void *content, size_t cs);
void					ft_lstpushback(t_list **begin_list,
							void *content, size_t cs);
void					convert_coords(t_visu *visu, t_adjlst *adjlst);
t_visu					*gen_map(t_adjlst *adjlst);
int						**get_map_coords(t_adjlst *adjlst,
							t_info *info, int max_x, int max_y);
t_list					*get_room_states(void);
double					ft_absdouble(double nb);
void					print_lines(t_visu *visu, t_adjlst *adjlst);
void					draw_square(t_visu *visu, int x, int y, int color);
void					display_dots2(t_visu *visu, t_adjlst *adjlst,
							int *x, t_info *info);
void					display_dots(t_visu *visu, t_adjlst *adjlst,
							t_info *info);
void					go_forward(t_visu *visu);
t_adjlst				*find_room_by_name(t_adjlst *adjlst, char *str);
t_list					*ft_lstatpos(t_list *begin_list, unsigned int nbr);
int						deal_key(int key, void *param);
void					free_visu(t_visu *visu);
void					freechar2(char **tab);
void					erreur(int code);
int						ft_bfc(t_adjlst *adjlst, t_info *info,
							t_queue *queue);
t_adjlst				*move_start_to_start(t_adjlst *adjlst,
							int pos, t_adjlst *temp);
int						getline_print(int fd, char **line);
void					ft_set_zero_testpath(t_info *info);
t_way					*ft_choose_second_way(t_way *temp_path,
							t_info *info, int *count);
int						ft_choose_way(t_adjlst *top, t_info *info);
t_way					*ft_set_fin_adder(t_way *path_one, t_info *info);
t_way					*ft_path_test(t_adjlst *list, t_info *info);
t_way					*ft_path_adder1(t_adjlst *list, t_links *link_reserve);
int						ft_valid_way(t_adjlst *node, t_info *info);
t_way					*ft_path_second_way(t_adjlst *list,
							t_info *info);
t_adjlst				*ft_path_adder_way(t_adjlst *list, t_adjlst
							*to_go, t_info *info);
int						ft_set_levels(t_adjlst *adjlst, t_info *info,
							t_queue *queue);
t_adjlst				*ft_what_min_vertex(t_adjlst *list);
void					ft_set_shortcut(t_info *info, int i);
void					ft_add_queue_final(t_queue *queue, t_info
							*info, int pos, int i);
int						ft_set_levels_final(t_adjlst *adjlst, t_info *info,
							t_queue *queue, int pos);
void					ft_set_paths(t_info *info);
int						link_by_link(t_adjlst *temp, t_adjlst *temp_2,
							char *pos_2);
void					ft_path_search_help(t_adjlst *list, t_adjlst *to_go,
							t_links *temp_link, t_info *info);
void					ft_path_search_help_2(t_adjlst *list, t_adjlst *to_go,
							t_links *temp_link, t_info *info);
void					ft_del_lst_q(t_queue **del);
void					ft_del_lst_ways(t_way **del);
t_queue					*ft_set_queue(t_adjlst *adjlst,
							int pos, t_info *info);
void					ft_add_paths(t_queue *queue,
							t_info *info, int pos);
int						ft_count_list(t_queue *queue);
void					ft_add_paths(t_queue *queue,
							t_info	*info, int pos);
t_way					*ft_path_test(t_adjlst *list,
							t_info *info);
void					ft_set_zero_testpath(t_info *info);
t_way					*ft_set_temp_path(t_adjlst *top);
int						ft_is_digital_str(char *str);
t_way					*ft_path_second_way(t_adjlst *list,
							t_info *info);
int						ft_valid_way(t_adjlst *node,
							t_info *info);
int						end(t_adjlst ***temp, t_info *info);
int						ft_move_ant(t_adjlst **temp,
							t_info *info, int *i);
int						print_ant(t_adjlst **temp,
							int len, t_info *info);
void					print_block(int ant, char *name);
int						ft_len_way(t_way *way);
int						ft_len_path(t_paths *way);
t_adjlst				***ft_get_array(t_paths *paths_all,
							t_info *info);
void					ft_set_ants_start(t_adjlst ***temp,
							t_info *info, int pos2);
int						ft_set_ant_return(t_adjlst **temp, int *len);
void					ft_print_ants(t_paths *paths_all, t_info *info);
void					ft_del_lst_path(t_paths **del);
void					ft_del_lst_adjlst(t_adjlst **del);
void					ft_del_lst_links(t_links **del);
t_adjlst				*ft_get_copy(t_adjlst *temp);
t_adjlst				*ft_set_links(t_info *info,
							t_adjlst *adjlst, char *fir);
t_adjlst				*ft_get_adjlst(char *line);
t_info					*ft_create_info(void);
int						ft_set_links_rooms(t_adjlst *adjlst,
							char *pos_1, char *pos_2);
t_adjlst				*ft_create_adjlst(t_info *info, int i, char *line);
t_paths					*ft_get_path(t_way *new, t_info *info);
int						ft_len_way(t_way *way);
t_way					*ft_path_start_test(t_adjlst *list);
int						ft_valid_way(t_adjlst *node, t_info *info);
t_way					*ft_path_test(t_adjlst *list, t_info *info);
int						ft_choose_way(t_adjlst *top, t_info *info);
t_way					*ft_path_search(t_adjlst *list, t_info *info);
t_links					*ft_get_lst(void *adjlst);
void					ft_lst_end(t_links **lst, t_links *new);
t_adjlst				*ft_get_adjlst(char *line);
void					ft_adjlst_end(t_adjlst **adjlst, t_adjlst *new,
							t_info *info, int flag);
void					ft_adjlst_end_help(t_adjlst **adjlst,
							t_info *info, int flag);
t_queue					*ft_get_queue(t_links *list, int pos,
							t_info *info, int rev);
int						ft_set_sum_rooms(t_adjlst *adjlst);
void					ft_add_toqueue_bfs(t_queue **queue, t_queue *new);
t_queue					*ft_set_queue_bfs(t_adjlst *adjlst,
							int pos, t_info *info);
int						ft_no_quene_bfs(t_queue *queue, t_queue *to_check);
void					ft_add_queue_bfs(t_queue *queue, t_info	*info, int pos);
t_adjlst				*ft_what_max_vertex(t_adjlst *adjlst);
void					ft_set_paths(t_info *info);
t_queue					*ft_set_queue(t_adjlst *adjlst, int pos, t_info *info);
int						ft_count_list(t_queue *queue);
void					ft_path_end(t_paths **lst, t_paths *new);
t_way					*ft_get_way_one(t_adjlst *new);
t_way					*ft_way_end(t_way **link, t_way *new);
int						ft_set_intersections(t_info *info);
t_way					*ft_path_start(t_adjlst *list, t_info *info);
t_way					*ft_path_addition(t_adjlst *list, t_info *info);
t_way					*ft_path(t_adjlst *list, t_info *info);
t_way					*ft_path_shortcut(t_adjlst *list, t_info *info);
t_paths					*ft_set_shortcut_path(t_info *info);
t_adjlst				***ft_get_array(t_paths *paths_all, t_info *info);
void					ft_clean_pos(char **pos_1, char **pos_2, char **pos_3);
int						links_errors(char *pos_1, char *pos_2,
								t_adjlst *adjlst, char *line);
int						ft_set_links_help(t_adjlst *adjlst, char **pos_1,
							char **pos_2, char *fir);
void					erreur(int code);
int						ft_set_ant_help(t_info *info);

#endif
