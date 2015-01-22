/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:55:06 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:55:06 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	erpretation;

	if (!s1 || !s2)
		return (2);
	erpretation = ft_strncmp(s1, s2, n);
	return ((erpretation * erpretation - 1) * (-1));
}
