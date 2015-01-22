/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:55:16 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:55:16 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*allocated;

	allocated = (char *)malloc(sizeof(char) * (size + 1));
	if (allocated == NULL)
		return (0);
	while (size + 1)
	{
		allocated[size] = 0;
		size--;
	}
	return (allocated);
}
