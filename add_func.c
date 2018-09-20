/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:21:41 by amasol            #+#    #+#             */
/*   Updated: 2018/09/19 12:21:42 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void 		check_symbol(t_room *rm)
{
	char *tmp;

	tmp = rm->tmp;
	while (*tmp)
	{
		if (*tmp == '/' || *tmp == ':' || *tmp == ';' || *tmp == '$' || *tmp == '%'
			   || *tmp == '[' || *tmp == ']' || *tmp == '=' || *tmp == '+'
			   || *tmp == '-' || *tmp == '(' || *tmp == ')' || *tmp == '&')
			error();
		tmp++;
	}
}