/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:52:23 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:52:23 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	j = ft_strlen(s1);
	i = 0;
	if (s2)
	{
		while (s2[i])
		{
			s1[j] = s2[i];
			i++;
			j++;
		}
	}
	s1[j] = '\0';
	return (s1);
}