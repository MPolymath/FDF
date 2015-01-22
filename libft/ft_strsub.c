/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:56:04 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:56:05 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	j;

	substr = ft_strnew(len);
	j = 0;
	if (substr == NULL || !s)
		return (NULL);
	while (j < len)
	{
		substr[j] = s[start];
		j++;
		start++;
	}
	return (substr);
}
