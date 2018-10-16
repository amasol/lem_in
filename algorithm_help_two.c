/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_help_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 20:33:44 by amasol            #+#    #+#             */
/*   Updated: 2018/10/16 20:33:47 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void 	lst_file_del_el_two(t_link **alst)
{
	t_link *temp;

	if (!alst || !*alst)
		return ;
	while (*alst)
	{
		temp = (*alst)->next;
		free((*alst));
		*alst = temp;
	}
	free(*alst);
	*alst = NULL;
}

void 	lst_file_del_el(t_f_link **alst)
{
	t_f_link *temp;

	if (!alst || !*alst)
		return ;
	while (*alst)
	{
		temp = (*alst)->next;
		free((*alst)->room_l);
		free((*alst));
		*alst = temp;
	}
	*alst = NULL;
}