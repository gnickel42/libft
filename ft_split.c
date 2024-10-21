/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:23:17 by gnickel           #+#    #+#             */
/*   Updated: 2024/10/21 14:43:03 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	i;
	size_t	w_count;

	i = 0;
	w_count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			w_count++;
		i++;
	}
	return (w_count);
}

static char	**actual_split(const char *s, char c, char **dst)
{
	size_t	i;
	size_t	sub_i;
	size_t	start;

	i = 0;
	sub_i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			dst[sub_i] = ft_substr(s, start, i - start + 1);
			if (!dst[sub_i])
			{
				while (sub_i > 0)
					free(dst[--sub_i]);
				return (free(dst), NULL);
			}
			sub_i++;
		}
		i++;
	}
	dst[sub_i] = NULL;
	return (dst);
}

char	**ft_split(const char *s, char c)
{
	char	**dst;

	if (!s)
		return (NULL);
	dst = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	dst = actual_split(s, c, dst);
	if (!dst)
	{
		free(dst);
		return (NULL);
	}
	return (dst);
}
