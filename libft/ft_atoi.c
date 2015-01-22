/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:47:48 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:47:49 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	int_erpretation;
	int	negative;

	negative = 1;
	int_erpretation = 0;
	while (*str == '\n' || *str == '\v' || *str == '\t' || *str == '\r'
			|| *str == '\f' || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		negative = (-1);
		str++;
	}
	while (ft_isdigit(*str))
	{
		int_erpretation = int_erpretation * 10 + (*str - 48);
		str++;
	}
	int_erpretation = int_erpretation * negative;
	return (int_erpretation);
}
