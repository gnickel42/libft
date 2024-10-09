/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:17:47 by gnickel           #+#    #+#             */
/*   Updated: 2024/10/09 16:00:33 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst_peter;
	const char	*src_peter;

	i = 0;
	dst_peter = dst;
	src_peter = src;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		dst_peter[i] = src_peter[i];
		i++;
	}
	return (dst_peter);
}
