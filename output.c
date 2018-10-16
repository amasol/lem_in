/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 19:08:39 by amasol            #+#    #+#             */
/*   Updated: 2018/10/02 19:08:41 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_f_link		*search_room_list(t_f_link *link, long int who)
{
	t_f_link *tmp;

	tmp = link;
	while (tmp)
	{
		if (tmp->who == who)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static void		substitution_output_helpp(t_ants **tmp,
				t_f_link **link)
{
	if ((*link)->access == 0 && (*tmp)->index == 0)
	{
		(*link)->access = 1;
		(*tmp)->index = 1;
		(*tmp)->was = (*link)->room_l;
		(*link)->who = (*tmp)->who;
		ft_putchar('L');
		ft_putnbr((*tmp)->who);
		ft_putchar('-');
		ft_putstr((*link)->room_l);
	}
}

static void		substitution_output_help(t_ants **tmp,
				t_f_link **link, t_ants **ants,t_gl **pr)
{
	if ((*link)->access == 1 && (*tmp)->index == 1 && (*tmp)->who != -1)
	{
		(*link) = search_room_list((*link), (*tmp)->who);
		if ((*tmp)->next != NULL)
			(*link)->access = 0;
		(*tmp)->index = 0;
		(*link)->who = 0;
		(*link) = (*link)->next;
		(*link)->access = 1;
		(*tmp)->index = 1;
		(*tmp)->was = (*link)->room_l;
		(*link)->who = (*tmp)->who;
		ft_putchar('L');
		ft_putnbr((*tmp)->who);
		ft_putchar('-');
		ft_putstr((*link)->room_l);
		ft_putchar(' ');
		ant_exit((*ants), (*pr));
		if ((*link)->next == NULL)
			(*tmp)->who = -1;
	}
}

static int		substitution_output_helppp(t_f_link **link, t_f_link **l_tmp,
				t_ants **ants, t_f_link **lst)
{
	(*link) = (*lst)->next;
	(*l_tmp) = (*lst)->next;
	if (!((*ants) = (t_ants*)malloc(sizeof(t_ants))))
		return (0);
	(*ants)->next = NULL;
	(*link)->access = 0;
	return (0);
}

void		free_ants(t_ants **ants)
{
	while ((*ants))
	{
		free((*ants));
		(*ants) = (*ants)->next;
	}
}

//функция которая выводит все в правильном порядке !
int 		substitution_output(t_f_link *lst, t_gl *pr)
{
	t_f_link *link;
	t_f_link *l_tmp;
	t_ants *ants;
	t_ants *tmp;

	substitution_output_helppp(&link, &l_tmp, &ants, &lst);
	ants = save_ants(ants, pr);
	tmp = ants;
	ft_putchar('\n');
	while (pr->close != 1)
	{
		while (tmp)
		{
			if (link->access == 0 && tmp->index == 0)
				substitution_output_helpp(&tmp, &link);
			else if (link->access == 1 && tmp->index == 1 && tmp->who != -1)
				substitution_output_help(&tmp, &link, &ants, &pr);
			tmp = tmp->next;
			link = l_tmp;
		}
		ft_putchar('\n');
		tmp = ants;
	}
	free_ants(&ants);
	return (0);
}
