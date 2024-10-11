/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:01:12 by gnickel           #+#    #+#             */
/*   Updated: 2024/10/11 11:39:23 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i_h;
	size_t	i_n;

	i_h = 0;
	if (!*needle)
		return ((char *)haystack);
	while (i_h < len && haystack[i_h])
	{
		i_n = 0;
		while (haystack[i_h + i_n] == needle[i_n] && (i_h + i_n) < len)
		{
			if (!needle[i_n + 1])
				return ((char *)&haystack[i_h]);
			i_n++;
		}
		i_h++;
	}
	return (0);
}
