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
	int				step;			//	шаг..
	char			*previous;		//	предыдущий
	int				x;
	int				y;
	struct s_room	*next;
}					t_room;

typedef struct		s_gl
{
	long int		ants;
	char			*map;
	char			*line;
	int				fd;
	int				start;
	int				end;
}					t_gl;

int				main(void);
int				parsing(t_gl *pr, t_room *rm);
void			ants_num(t_gl *pr);
void			extra_lines(t_gl *pr);
void			comment(t_gl *pr);
void			not_vld_word(t_gl *pr);
void			check_start(t_gl * pr);
void			save_room_s(t_gl *pr, t_room *rm);
void			error();
void			error_word(t_room *rm);

#endif

