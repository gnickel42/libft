/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:52:41 by gnickel           #+#    #+#             */
/*   Updated: 2024/10/14 13:52:41 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*dst;
	size_t	i;
	size_t	i_set;

	i = 0;
	i_set = 0;
	while (dst)
		while (set)
		{
			while (s1[i] == set[i_set])
				i++;
			i_set++;
		}
}
