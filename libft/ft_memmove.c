/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:50:43 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:50:43 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*scpy;
	size_t	j;

	scpy = (char *)malloc(sizeof(char) * n);
	j = 0;
	while (j < n)
	{
		scpy[j] = ((char *)s2)[j];
		j++;
	}
	while (n > 0)
	{
		n--;
		((char *)s1)[n] = scpy[n];
	}
	return (s1);
}
