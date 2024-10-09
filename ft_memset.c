/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:43:53 by gnickel           #+#    #+#             */
/*   Updated: 2024/10/09 14:56:15 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*peter;

	peter = (unsigned char *)b;
	while (len > 0)
	{
		len--;
		*peter = (unsigned char) c;
		peter++;
	}
	return (b);
}
