/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 19:30:57 by amasol            #+#    #+#             */
/*   Updated: 2018/09/23 19:30:58 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		line_l(t_gl *pr)
{
	if (pr->line && *pr->line == 'L')
	{
		ft_putstr("Error validation\n");
		exit(1);
	}
}

int			error_st_end(t_gl *pr)
{
	if (pr->first == NULL || pr->last == NULL)
		error();
	else if (pr->link_yes == 0)
		error();
	return (0);
}
