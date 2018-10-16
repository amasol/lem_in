/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_room_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 02:50:41 by amasol            #+#    #+#             */
/*   Updated: 2018/09/24 02:50:42 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			zero_l_h(t_gl *pr)
{
	pr->l_k = 0;
	pr->l_m = 0;
	pr->l_s = 0;
	pr->i = 0;
	pr->l_h = 0;
}

void			check_link(t_gl *pr)
{
	if (pr->go_link == 1)
	{
		pr->link_yes = 1;
		pr->link = create_link(&(pr->link));
		save_link(pr, pr->link);
		save_link_help(pr);
		if (pr->l_k == 1 || pr->l_k > 2 || pr->l_k == 0)
			error();
	}
}

int				save_link_help_two(char *str, t_gl *pr)
{
	int		k;
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	k = 0;
	pr->link->one_h = pr->link->one;
	pr->link->two_h = pr->link->two;
	j = ft_strlen(str);
	while (i != j + 1)
	{
		if (i == j && (pr->link->one == 1 && pr->link->two == 1))
		{
			pr->link->one = pr->link->one_h;
			pr->link->two = pr->link->two_h;
		}
		tmp = ft_strsub(str, 0, i);
		k = comparison_room_link(pr, tmp);
		i++;
		free(tmp);
	}
	if (k == 1)
		return (1);
	return (k);
}

void			save_l_hh(t_gl *pr, char *str)
{
	char *tmp;

	tmp = str;
	pr->l_h++;
	pr->l_m -= pr->l_s;
	str = ft_strsub(tmp, pr->l_h, pr->l_m);
	pr->l_k += save_link_help_two(str, pr);
	free(str);
}
