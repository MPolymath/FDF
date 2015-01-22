/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:56:25 by mdiouf            #+#    #+#             */
/*   Updated: 2014/12/28 17:56:25 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	space;
	size_t	i;

	if (!s)
		return (NULL);
	space = ft_strlen(s);
	i = 0;
	while (s[space - 1] == ' ' || s[space - 1] == '\n' || s[space - 1] == '\t')
		space--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && space != 0)
		i++;
	return (ft_strncpy(ft_strnew(space - i), s + i, space - i));
}
