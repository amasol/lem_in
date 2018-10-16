/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:14:14 by amasol            #+#    #+#             */
/*   Updated: 2018/09/20 17:14:15 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			check_room(t_gl *pr)
{
	if (check_link_no_room(pr))
		;
	else if (pr)
	{
		pr->rms = create_room(&(pr->rms));
		if (pr->start == 1 && pr->end == 0 && pr->go_link == 0 &&
			pr->start_let != 1)
		{
			save_room(pr, pr->rms);
			pr->first = pr->rms;
			pr->start = 0;
			pr->start_let = 1;
		}
		else if (pr->end == 1 && pr->end_let != 1)
		{
			save_room(pr, pr->rms);
			pr->last = pr->rms;
			pr->end = 0;
			pr->end_let = 1;
		}
		else
			save_room(pr, pr->rms);
	}
}

void			save_room(t_gl *pr, t_room *rm)
{
	char	**tmp;
	int		len;

	pr->i = 0;
	if (pr->line && *pr->line && *pr->line != 'L')
	{
		if (pr->space > 2)
			error();
		tmp = ft_strsplit(pr->line, ' ');
		len = arr_len(tmp);
		if (len > 3 || len < 3)
			error();
		save_room_help(rm, tmp);
		rm->tmp = NULL;
		while (tmp[pr->i])
			free(tmp[pr->i++]);
		free(tmp);
	}
	line_l(pr);
}

void			save_room_help(t_room *rm, char **tmp)
{
	rm->name_r = ft_strdup(tmp[0]);
	check_xy(tmp[1]);
	check_xy(tmp[2]);
	rm->x = ft_atoi(tmp[1]);
	rm->y = ft_atoi(tmp[2]);
	rm->tmp = tmp[1];
	error_word(rm);
	rm->tmp = tmp[2];
	error_word(rm);
}

int				save_link(t_gl *pr, t_link *link)
{
	link->one = 0;
	link->two = 0;
	pr->i = 0;
	pr->link->tmp = (char *)malloc(sizeof(char));
	if (pr->line && *pr->line)
		pr->link->tmp = ft_strcat(link->tmp, pr->line);
	return (0);
}

int				save_link_help(t_gl *pr)
{
	char *tmp;
	char *str;

	zero_l_h(pr);
	str = pr->line;
	pr->l_m = ft_strlen(str);
	while (str && str[pr->l_h])
	{
		while (str[pr->l_h] != '-' && str[pr->l_h])
			pr->l_h++;
		if (str[pr->l_h] == '-')
		{
			tmp = ft_strsub(str, 0, pr->l_h);
			pr->l_s = ft_strlen(tmp);
			pr->l_k = comparison_room_link(pr, tmp);
			free(tmp);
			if (pr->l_k == 1)
				save_l_hh(pr, str);
			if (pr->l_k == 2)
				return (0);
		}
		pr->l_h++;
	}
	return (0);
}
