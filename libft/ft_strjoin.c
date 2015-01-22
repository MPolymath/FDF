/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:53:44 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:53:44 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*to_stock_joined;

	to_stock_joined = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	return (ft_strcat(ft_strcat(to_stock_joined, s1), s2));
}
