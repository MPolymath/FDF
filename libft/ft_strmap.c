/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:54:09 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:54:09 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*s_fresh_str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	s_fresh_str = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		s_fresh_str[i] = f(s[i]);
		i++;
	}
	return (s_fresh_str);
}
