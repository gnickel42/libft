/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:23:17 by gnickel           #+#    #+#             */
/*   Updated: 2024/10/17 10:49:42 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	sp_dechar(const char *s, char c)
{
	size_t	i;
	size_t	dechar;

	i = 0;
	dechar = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			dechar++;
		i++;
	}
	return (dechar);
}

static char	*sp_helper(const char *s, char c, char **dst)
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
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
		{
			dst[sub_i] = ft_substr(s, start, i - start + 1);
			if (!dst[sub_i])
				return (NULL);
			sub_i++;
		}
		i++;
	}
	dst[sub_i] = NULL;
	return (*dst);
}

static void	sp_free(char **split)
{
	char **tmp;

	tmp = split;
	while (*tmp)
		free(*tmp++);
	free(split);
}

char	**ft_split(const char *s, char c)
{
	char	**dst;

	if (!s)
		return (NULL);
	dst = (char **)malloc((sp_dechar(s, c) + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	if (!sp_helper(s, c, dst))
	{
		sp_free(dst);
		return (NULL);
	}
	return (dst);
}
