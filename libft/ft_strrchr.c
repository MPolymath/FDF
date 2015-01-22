/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:55:36 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:55:36 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurence;

	last_occurence = NULL;
	while (*s != 0)
	{
		if (*s == (char)c)
			last_occurence = (char *)s;
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (last_occurence);
}
