/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:54:40 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:54:47 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && i < n)
		i++;
	if (i == n || (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]) == 0)
		return (0);
	else if (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i] > 0)
		return (1);
	else
		return (-1);
}
