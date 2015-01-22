/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:51:42 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:51:42 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nbr)
{
	int	nbrtoput;

	nbrtoput = nbr % 10;
	nbr = nbr / 10;
	if (nbrtoput < 0)
	{
		ft_putchar('-');
		nbr = nbr * (-1);
		if (nbrtoput < 0)
			nbrtoput = nbrtoput * (-1);
	}
	if (nbr)
		ft_putnbr(nbr);
	ft_putchar(nbrtoput + 48);
}
