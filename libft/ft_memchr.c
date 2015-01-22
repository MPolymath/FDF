/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:49:57 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:49:58 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (NULL);
	while (n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(((unsigned char *)s) + i));
		i++;
		n--;
	}
	return (NULL);
}
