/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:49:25 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:49:26 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int		ft_ispositive(int n)
{
	if (n >= 0)
		return (0);
	return (-1);
}

char			*ft_itoa(int n)
{
	int		sign;
	char	*nbr_str;
	size_t	nbrlen;

	sign = ft_ispositive(n);
	nbrlen = ft_nbrlen(n);
	nbr_str = (char *)malloc(sizeof(char) * (nbrlen - sign));
	if (!nbr_str)
		return (NULL);
	if (sign)
		nbr_str[0] = '-';
	nbr_str[nbrlen - sign] = 0;
	while (nbrlen != 0)
	{
		nbr_str[nbrlen - 1 - sign] = (char)((1 + 2 * sign) * (n % 10) + 48);
		nbrlen--;
		n = n / 10;
	}
	return (nbr_str);
}
