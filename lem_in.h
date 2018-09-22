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
	char			*name_r;
	char			*tmp;
//	int				start;
//	int				end;
//	int				step;			//	шаг..
//	char			*previous;		//	предыдущий
	long int		x;
	long int		y;
	struct s_room	*next;
}					t_room;

typedef	struct		s_link
{
	char			*name_l_one;
	char			*name_l_two;
	char			*tmp;
//	int				step;			//	шаг..
//	char			*previous;		//	предыдущий
	struct s_link	*next;
}					t_link;

typedef struct		s_gl
{
	t_room 			*rms;
	t_link			*link;
	t_room			*first;
	t_room			*last;


	int				space;
	char			*str_free;
	long int		ants;
	char			*map;
	char			*line;
	int				fd;
	int				start;
	int				end;
	int				dop_st;
	int				dop_en;
	int				check_room;
	int				i;
	int				com;
	int				go_link;

}					t_gl;

int				main(void);
int				parsing(t_gl *pr);
void			ants_num(t_gl *pr);
void			extra_lines(t_gl *pr);
void			comment(t_gl *pr);
void			not_vld_word(t_gl *pr);
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
void			error_check(t_gl *pr);
int				num_spac(t_gl *pr);
int 			arr_len(char **str);
int				link_line(char *tmp);
//void			valid_st_end(t_gl *pr);
int				comparison_line(t_gl *pr);
int				comparison_link(t_gl *pr);
void			save_link(t_gl *pr, t_link *link);
int				comparison_link_dop(t_gl *pr);
void			valid_double_link(t_gl *pr);

#endif

