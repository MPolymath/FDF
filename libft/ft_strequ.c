/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:53:16 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:53:17 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	erpretation;

	if (!s1 || !s2)
		return (2);
	erpretation = ft_strcmp(s1, s2);
	return ((erpretation * erpretation - 1) * (-1));
}
