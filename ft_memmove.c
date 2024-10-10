/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:07:54 by gnickel           #+#    #+#             */
/*   Updated: 2024/10/10 09:07:54 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dst_peter;
	const char	*src_peter;

	dst_peter = dst;
	src_peter = src;
	if (!dst && !src)
		return (dst);
	if (dst_peter > src_peter)
	{
		i = len;
		while (i-- > 0)
			dst_peter[i] = src_peter[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst_peter[i] = src_peter[i];
			i++;
		}
	}
	return (dst_peter);
}
