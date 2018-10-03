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

typedef	struct		s_room
{
	int				repeat;
	char			*name_r;
	char			*tmp;
	long int		x;
	long int		y;
	struct s_room	*next;
}					t_room;

typedef	struct		s_link
{
	int				search_short;
	int				skipping;
	int				skipping_two;
	int				one;
	int				one_h;
	int				two;
	int				two_h;
	char			*name_l_one;
	char			*name_l_two;
	char			*tmp;
	int				step;
	int				start_let;
	char			**way;
	char			*way_room;
	struct s_link	*next;
//	struct s_link	*prv;
}					t_link;

typedef struct		s_gl
{
	t_room			*map;
	t_room 			*rms;
	t_link			*link;
	t_room			*first;
	t_room			*last;
	t_link 			*queue;



	int				l_k;
	int				l_h;
	int				l_m;
	int				l_s;
	int				space;
	long int		ants;
	int			ants_flag;
	char			*line;
	int				fd;
	int				start;
	int				end;
//	int				start_let;
	int				end_let;
	int				check_room;
	int				i;
	int				com;
	int				go_link;
	int 			check_st_en;
	int				link_yes;
	int				way;

}					t_gl;

int				main(void);
int				parsing(t_gl *pr);
void			ants_num(t_gl *pr);
void			comment(t_gl *pr);
void			check_start(t_gl *pr);
void			error();
void			error_word(t_room *rm);
void			check_symbol(t_room *rm);
t_room			*create_room(t_room **rm);
t_link			*create_link(t_link **rm);
void			check_room(t_gl *pr);
void			save_room(t_gl *pr, t_room *rm);
void			line_l(t_gl *pr);
void			check_link(t_gl *pr);
int				error_st_end(t_gl *pr);
int				num_spac(t_gl *pr);
int 			arr_len(char **str);
int				comparison_line(t_gl *pr);
int				comparison_link(t_gl *pr);
int				save_link(t_gl *pr, t_link *link);
int				comparison_link_dop(t_gl *pr);
int				save_link_help(t_gl *pr);
int				save_link_help_two(char *str, t_gl *pr);
int				comparison_room_link(t_gl *pr, char *tmp);
void			check_error(t_gl *pr);
void			save_map(t_gl *pr);
t_room			*create_map(t_room **rm);
int				check_link_no_room(t_gl *pr);

void			zero(t_gl *pr);
void			check_start_h_s(t_gl *pr);
void			check_start_h_e(t_gl *pr);
void			check_xy(char *tmp);
void			check_start_h_com(t_gl *pr);
void			save_room_help(t_room *rm, char **tmp);
void			save_l_hh(t_gl *pr, char *str);
void			zero_l_h(t_gl *pr);


t_link			*algorithm(t_gl *pr);
int				search_connection(t_gl *pr, t_link *search_r);
int				ft_list_size(t_link *begin_list);
void			check_end(t_gl *pr, t_link *search_tmp);
int				save_way(t_link *search_tmp, char *str);
void			definition_short(t_link *search_tmp);
//t_link			*search_short(t_link *search_tmp);
void			search_short(t_link *search_tmp);
void			swap(t_link *tmp, t_link *tmp_two);

void			output(t_gl *pr, t_link *search);



#endif

