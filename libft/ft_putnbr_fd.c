/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:51:50 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:51:50 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	int	nbrtoput;

	nbrtoput = nbr % 10;
	nbr = nbr / 10;
	if (nbrtoput < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = nbr * (-1);
		if (nbrtoput < 0)
			nbrtoput = nbrtoput * (-1);
	}
	if (nbr)
		ft_putnbr_fd(nbr, fd);
	ft_putchar_fd(nbrtoput + 48, fd);
}
