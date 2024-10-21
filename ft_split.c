/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:23:17 by gnickel           #+#    #+#             */
/*   Updated: 2024/10/21 10:34:21 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static size_t	word_count(const char *s, char c)
{
	size_t	i;
	size_t	w_count;

	i = 0;
	w_count = 0;
	while (s[i])
	{
		if (c == '\0')
			break;
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			w_count++;
		i++;
		// printf("i: %zu, w: %zu\n", i, w_count);
	}
	return (w_count);
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
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			dst[sub_i] = ft_substr(s, start, i - start + 1);
			if(!dst[sub_i])
			{
				while (sub_i > 0)
					free(dst[--sub_i]);
				free(dst);
				return (NULL);
			}
			sub_i++;
		}
		i++;
	}
	dst[sub_i] = NULL;
	return (*dst);
}

static void	sp_free(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(const char *s, char c)
{
	char	**dst;
	size_t	words;

	if (!s)
		return (NULL);
	if (c == '\0')
        return (dst = ft_calloc(1, sizeof(char *)));
	words = word_count(s, c);
	if (s[0] == '\0' || words == 0)
		return (dst = ft_calloc(1, sizeof(char *)));
	dst = (char **)malloc((words + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	if (!sp_helper(s, c, dst))
	{
		sp_free(dst);
		return (NULL);
	}
	return (dst);
}

// int	main(void) {
// 	char **dst = ft_split("nonempty", 0:'\0');
// 	printf("result[0] = '%s'\n", dst[0]);
// 	printf("result[1] = %p\n", dst[1]); // Should be NULL
// 	for (size_t i = 0; ; i++) {
// 		if (dst[i] != NULL) {
// 			printf("%zu: %s\n", i, dst[i]); // Print the string
//
// 			// Inner loop to print each character in dst[i]
// 			size_t j = 0;
// 			while (dst[i][j] != '\0') {  // Instead of using strlen, just check for '\0'
// 				printf("  [%zu][%zu]: %c\n", i, j, dst[i][j]); // Print each char
// 				j++;
// 			}
// 			// After the loop, print the position of the NULL terminator
// 			printf("  [%zu][%zu]: NULL\n", i, j);
//
// 		} else {
// 			printf("%zu: NULL\n", i); // Print "NULL" for the NULL terminator
// 			break; // Exit the loop when we hit the NULL
// 		}
// 	}
// }
