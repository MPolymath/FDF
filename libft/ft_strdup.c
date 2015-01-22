/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:53:08 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:53:08 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*scopy;

	scopy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (scopy == NULL)
		return (NULL);
	ft_strcpy(scopy, str);
	return (scopy);
}
