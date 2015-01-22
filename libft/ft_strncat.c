/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:54:27 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:54:28 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int	i;
	int	j;

	j = ft_strlen(s1);
	i = 0;
	while (n && s2[i] != 0)
	{
		s1[j] = s2[i];
		i++;
		j++;
		n--;
	}
	s1[j] = 0;
	return (s1);
}
