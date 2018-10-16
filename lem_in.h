/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:51:29 by amasol            #+#    #+#             */
/*   Updated: 2018/09/15 14:51:30 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN
# include "./libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef	struct		s_ants
{
	int				index;
	char			*was;
	long int		who;
	struct s_ants	*next;
}					t_ants;

typedef	struct		s_f_link
{
	int				last_room;
	int				access;
	long int		who;
	char			*room_l;
	struct s_f_link	*next;
}					t_f_link;

typedef	struct		s_room
{
	char			*name_r;
	char			*tmp;
	long int		x;
	long int		y;
	struct s_room	*next;
}					t_room;

typedef	struct		s_link
{
	int				count;
	int				line;
	char			*room_next;
	int				index;
	int				last_room;
	int				one;
	int				one_h;
	int				two;
	int				two_h;
	char			*name_l_one;
	char			*name_l_two;
	char			*tmp;
	struct s_link	*last;
	struct s_link	*next;
}					t_link;

typedef struct		s_gl
{
	t_room			*rms;
	t_link			*link;
	t_room			*first;
	t_room			*last;

	int				end_of_file;
	int				close;
	int				l_k;
	int				l_h;
	int				l_m;
	int				l_s;
	int				space;
	long int		ants;
	int				ants_flag;
	char			*line;
	int				fd;
	int				start;
	int				end;
	int				start_let;
	int				end_let;
	int				i;
	int				com;
	int				go_link;
	int				link_yes;
}					t_gl;

int					main(void);
int					parsing(t_gl *pr);
void				ants_num(t_gl *pr);
void				check_start(t_gl *pr);
void				error(void);
void				error_word(t_room *rm);
void				check_symbol(t_room *rm);
t_room				*create_room(t_room **rm);
t_link				*create_link(t_link **rm);
void				check_room(t_gl *pr);
void				save_room(t_gl *pr, t_room *rm);
void				line_l(t_gl *pr);
void				check_link(t_gl *pr);
int					error_st_end(t_gl *pr);
int					num_spac(t_gl *pr);
int					arr_len(char **str);
int					comparison_line(t_gl *pr);
int					comparison_link(t_gl *pr);
int					save_link(t_gl *pr, t_link *link);
int					comparison_link_dop(t_gl *pr);
int					save_link_help(t_gl *pr);
int					save_link_help_two(char *str, t_gl *pr);
int					comparison_room_link(t_gl *pr, char *tmp);
void				check_error(t_gl *pr);
t_room				*save_map(t_gl *pr, t_room *map);
t_room				*create_map(t_room **rm);
int					check_link_no_room(t_gl *pr);
void				check_start_h_s(t_gl *pr);
void				check_start_h_e(t_gl *pr);
void				check_xy(char *tmp);
void				check_start_h_com(t_gl *pr);
void				save_room_help(t_room *rm, char **tmp);
void				save_l_hh(t_gl *pr, char *str);
void				zero_l_h(t_gl *pr);
t_link				*algorithm(t_gl *pr, t_room *map);
int					definition_short(t_f_link *search_tmp,
						t_gl *pr, t_room *map);
int					substitution_output(t_f_link *lst, t_gl *pr);
t_ants				*save_ants(t_ants *ants, t_gl *pr);
int					one_room(t_f_link *lst, t_gl *pr);

void				ant_exit(t_ants *ants, t_gl *pr);
void				ft_list_reverse(t_f_link **begin_list);
void				output_map(t_room *map);
void				initialization(t_link **search);
t_f_link			*end_algorithm(t_link *search, t_f_link *end_link);
t_f_link			*check_end(char *last_room, t_link *search_tmp);
void				free_ants(t_ants **ants);
t_link				*search_help(t_link *tmp);
void				lst_file_del_el(t_f_link **alst);
void				lst_file_del_el_two(t_link **alst);

#endif
