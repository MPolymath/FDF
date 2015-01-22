/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:55:24 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:55:25 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		last_begin_detected;
	int		actual_checked_char;
	size_t	i;

	i = 0;
	if (s2[i] == 0)
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		actual_checked_char = 0;
		if (s1[i] == s2[actual_checked_char])
		{
			last_begin_detected = i;
			while (s1[i] == s2[actual_checked_char] && i < n)
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
