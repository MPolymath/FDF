/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:58:05 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:58:05 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	int	i;

	i = 0;
	if (n < 1)
		return (NULL);
	while (n)
	{
		((char *)s1)[i] = ((char *)s2)[i];
		i++;
		if (((unsigned char *)s2)[i - 1] == (unsigned char)c)
			return ((void *)(((unsigned char *)s1) + i));
		n--;
	}
	return (NULL);
}
