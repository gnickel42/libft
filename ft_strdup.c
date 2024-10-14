/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:23:26 by gnickel           #+#    #+#             */
/*   Updated: 2024/10/14 12:23:26 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = malloc(ft_strlen(s1) + 1);
	if (dst)
	{
		while (i < ft_strlen(s1))
		{
			dst[i] = s1[i];
			i++;
		}
		dst[i] = 0;
	}
	return (dst);
}
