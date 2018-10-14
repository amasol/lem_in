/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:37:20 by amasol            #+#    #+#             */
/*   Updated: 2017/11/20 14:27:21 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	if (nb < 10)
		ft_putchar(nb + '0');
}
