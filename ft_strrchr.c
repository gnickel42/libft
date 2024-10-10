/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:26:14 by gnickel           #+#    #+#             */
/*   Updated: 2024/10/10 14:26:14 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (!(unsigned char)c)
		return ((char *)&s[ft_strlen(s)]);
	while (i--)
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
	return (0);
}
