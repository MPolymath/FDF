/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:54:18 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:54:18 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_fresh_str;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	s_fresh_str = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		s_fresh_str[i] = f(i, s[i]);
		i++;
	}
	return (s_fresh_str);
}
