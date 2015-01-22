/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:49:35 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:49:36 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*allocated;

	allocated = (char *)malloc(sizeof(char) * size);
	while (size && allocated != 0)
	{
		allocated[size - 1] = 0;
		size--;
	}
	return (allocated);
}
