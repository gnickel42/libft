/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:36:05 by gnickel           #+#    #+#             */
/*   Updated: 2024/10/16 10:36:05 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	if (s1 || set)
	{
		while (ft_strchr(set, s1[start]) && s1[start])
			start++;
		while (ft_strrchr(set, s1[end]) && end > 0)
			end--;
		end++;
		return (ft_substr(s1, start, end - start));
	}
	return (NULL);
}
