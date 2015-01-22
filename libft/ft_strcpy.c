/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:52:53 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:52:53 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (1)
	{
		s1[i] = s2[i];
		if (s2[i] == 0)
			return (s1);
		i++;
	}
}
