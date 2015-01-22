/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:53:51 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:53:51 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_dst_and_src;
	size_t	free_size;

	len_dst = ft_strlen(dst);
	if ((int)size - (int)len_dst <= 0)
		return (ft_strlen(src) + size);
	i = 0;
	len_dst_and_src = len_dst + ft_strlen(src);
	free_size = size - len_dst - 1;
	while (free_size && src[i])
	{
		dst[len_dst] = src[i];
		i++;
		len_dst++;
		free_size--;
	}
	dst[len_dst] = 0;
	return (len_dst_and_src);
}
