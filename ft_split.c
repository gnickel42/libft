/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:23:17 by gnickel           #+#    #+#             */
/*   Updated: 2024/10/16 15:53:53 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>


char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	dechar;
	size_t	i;
	size_t	sub_i;
	size_t	start;

	i = 0;
	dechar = 1;
	sub_i = 0;
	start = 0;
	if (!s || !c)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
			start = 1;
		if (s[i] == c && start > 0)
		{
			dechar++;
			start = 0;
		}
		i++;
	}

	if (dechar == 1) {
		dst = (char **)malloc(2 * sizeof(char *)); // Allocate space for 2 elements
		if (!dst)
			return (NULL); // Handle memory allocation failure
		dst[0] = ft_strdup((char *)s); // Copy the string
		if (!dst[0]) {
			free(dst); // Clean up in case strdup fails
			return (NULL);
		}
		dst[1] = NULL; // NULL-terminate the array
		return (dst);
	}
	dst = (char **)malloc(dechar * sizeof(char *) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] != c)
			start++;
		if (s[i] == c && start > 0)
		{
			dst[sub_i] = ft_substr(s, i - start, start);
			sub_i++;
			start = 0;
		}
		i++;
	}
	if (start < i)
		dst[sub_i] = ft_substr(s, i - start, start);
	dst[sub_i+1] = NULL;
	return (dst);
}

// int	main(void) {
// 	char **dst = ft_split("mi.", 'z');
// 	for (size_t i = 0; ; i++) { // No condition in the for loop
// 		if (dst[i] != NULL) {
// 			printf("%zu: %s\n", i, dst[i]); // Print the string
// 		} else {
// 			printf("%zu: NULL\n", i); // Print "NULL" for the NULL terminator
// 			break; // Exit the loop when we hit the NULL
// 		}
// 	}
// }