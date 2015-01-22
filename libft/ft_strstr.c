/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:55:57 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:55:58 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	last_begin_detected;
	int	actual_checked_char;
	int	i;

	i = 0;
	if (s2[i] == 0)
		return ((char *)s1);
	while (s1[i])
	{
		actual_checked_char = 0;
		if (s1[i] == s2[actual_checked_char])
		{
			last_begin_detected = i;
			while (s1[i] == s2[actual_checked_char])
			{
				i++;
				actual_checked_char++;
				if (s2[actual_checked_char] == 0)
					return ((char *)s1 + last_begin_detected);
			}
			i = last_begin_detected;
		}
		i++;
	}
	return (NULL);
}
